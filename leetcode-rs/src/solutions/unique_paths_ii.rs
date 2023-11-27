use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    63,
    "Unique Paths II",
    [
        vec![vec![0, 0, 0], vec![0, 1, 0], vec![0, 0, 0]],
        vec![vec![0, 1], vec![0, 0]],
        vec![vec![1, 0]],
        vec![vec![0, 0], vec![1, 1], vec![0, 0]]
    ],
    [2, 1, 0, 0],
    Self::unique_paths_with_obstacles
);

impl SolutionImpl {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();
        let mut dp = vec![vec![0; n]; m];

        #[allow(clippy::needless_range_loop)]
        for i in 0..m {
            if obstacle_grid[i][0] != 1 {
                dp[i][0] = 1;
            } else {
                break;
            }
        }
        for i in 0..n {
            if obstacle_grid[0][i] != 1 {
                dp[0][i] = 1;
            } else {
                break;
            }
        }

        for i in 1..m {
            for j in 1..n {
                dp[i][j] = if obstacle_grid[i][j] == 1 {
                    0
                } else {
                    dp[i - 1][j] + dp[i][j - 1]
                };
            }
        }

        dp[m - 1][n - 1]
    }
}

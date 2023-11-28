use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    64,
    "Minimum Path Sum",
    [
        vec![vec![1, 3, 1], vec![1, 5, 1], vec![4, 2, 1]],
        vec![vec![1, 2, 3], vec![4, 5, 6]]
    ],
    [7, 12],
    Self::min_path_sum
);

impl SolutionImpl {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut dp = vec![vec![0; n]; m];

        let mut sum = 0;
        for i in 0..m {
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        sum = 0;
        for i in 0..n {
            sum += grid[0][i];
            dp[0][i] = sum;
        }

        for i in 1..m {
            for j in 1..n {
                dp[i][j] = grid[i][j] + dp[i - 1][j].min(dp[i][j - 1]);
            }
        }

        dp[m - 1][n - 1]
    }
}

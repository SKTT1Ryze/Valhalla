use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    62,
    "Unique Paths",
    [(3, 7), (3, 2)],
    [28, 3],
    |(m, n)| Self::unique_paths(m, n)
);

impl SolutionImpl {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let m = m as usize;
        let n = n as usize;
        let mut dp = vec![vec![0; n]; m];

        #[allow(clippy::needless_range_loop)]
        for i in 0..m {
            dp[i][0] = 1;
        }
        for i in 0..n {
            dp[0][i] = 1;
        }

        for i in 1..m {
            for j in 1..n {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        dp[m - 1][n - 1]
    }
}

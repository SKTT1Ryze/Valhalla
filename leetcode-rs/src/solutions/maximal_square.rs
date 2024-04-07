use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    221,
    "Maximal Square",
    [
        vec![
            vec!['1', '0', '1', '0', '0'],
            vec!['1', '0', '1', '1', '1'],
            vec!['1', '1', '1', '1', '1'],
            vec!['1', '0', '0', '1', '0']
        ],
        vec![vec!['0', '1'], vec!['1', '0']]
    ],
    [4, 1],
    Self::maximal_square
);

impl SolutionImpl {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        let m = matrix.len();
        if m == 0 {
            return 0;
        }
        let n = matrix[0].len();
        let mut dp = vec![vec![0; n + 1]; m + 1];
        let mut max_side = 0;

        for i in 1..=m {
            for j in 1..=n {
                if matrix[i - 1][j - 1] == '1' {
                    dp[i][j] = dp[i - 1][j - 1]
                        .min(dp[i - 1][j].min(dp[i][j - 1]))
                        + 1;
                    max_side = max_side.max(dp[i][j]);
                }
            }
        }

        (max_side * max_side) as i32
    }
}

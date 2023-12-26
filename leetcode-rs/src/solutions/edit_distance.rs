use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    72,
    "Edit Distance",
    [
        ("horse", "ros"),
        ("intention", "execution"),
        ("", "a"),
        ("a", "ab")
    ],
    [3, 5, 1, 1],
    |(word1, word2)| Self::min_distance(word1.into(), word2.into())
);

impl SolutionImpl {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let word1: Vec<_> = word1.chars().collect();
        let word2: Vec<_> = word2.chars().collect();
        let m = word1.len();
        let n = word2.len();
        let mut dp = vec![vec![0; n + 1]; m + 1];

        for i in 1..=m {
            dp[i][0] = i as i32;
        }
        for j in 1..=n {
            dp[0][j] = j as i32;
        }

        for i in 1..=m {
            for j in 1..=n {
                if word1[i - 1] == word2[j - 1] {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        (dp[i][j - 1]).min(dp[i - 1][j]).min(dp[i - 1][j - 1])
                            + 1;
                }
            }
        }

        dp[m][n]
    }
}

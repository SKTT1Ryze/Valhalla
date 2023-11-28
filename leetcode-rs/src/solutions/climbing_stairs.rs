use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    70,
    "Climbing Stairs",
    [2, 3],
    [2, 3],
    Self::climb_stairs
);

impl SolutionImpl {
    pub fn climb_stairs(n: i32) -> i32 {
        if n == 1 {
            return 1;
        }
        let n = n as usize;
        let mut dp = vec![0; n + 1];

        dp[1] = 1;
        dp[2] = 2;

        for i in 3..=n {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        dp[n]
    }
}

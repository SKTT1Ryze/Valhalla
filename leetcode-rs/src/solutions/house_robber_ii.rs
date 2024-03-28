use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    213,
    "House Robber II",
    [vec![2, 3, 2], vec![1, 2, 3, 1], vec![1, 2, 3]],
    [3, 4, 3],
    Self::rob
);

impl SolutionImpl {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 1 {
            nums[0]
        } else if n == 2 {
            nums[0].max(nums[1])
        } else {
            Self::rob_circle(&nums, true).max(Self::rob_circle(&nums, false))
        }
    }

    pub fn rob_circle(nums: &[i32], rob_at_first: bool) -> i32 {
        let n = nums.len();
        let mut dp = vec![0; n];

        if rob_at_first {
            dp[0] = nums[0];
            dp[1] = nums[0];
        } else {
            dp[1] = nums[1];
        }

        for i in 2..n {
            if i == n - 1 && rob_at_first {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1].max(dp[i - 2] + nums[i]);
            }
        }

        dp[n - 1]
    }
}

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    45,
    "Jump Game II",
    [
        vec![2, 3, 1, 1, 4],
        vec![2, 3, 0, 1, 4],
        vec![
            5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1,
            6, 8, 8, 4, 4, 2, 0, 3, 8, 5
        ],
        vec![
            8, 2, 4, 4, 4, 9, 5, 2, 5, 8, 8, 0, 8, 6, 9, 1, 1, 6, 3, 5, 1, 2, 6, 6, 0, 4, 8, 6, 0,
            3, 2, 8, 7, 6, 5, 1, 7, 0, 3, 4, 8, 3, 5, 9, 0, 4, 0, 1, 0, 5, 9, 2, 0, 7, 0, 2, 1, 0,
            8, 2, 5, 1, 2, 3, 9, 7, 4, 7, 0, 0, 1, 8, 5, 6, 7, 5, 1, 9, 9, 3, 5, 0, 7, 5
        ]
    ],
    [2, 2, 5, 13],
    Self::jump
);

impl SolutionImpl {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![i32::MAX; n];
        dp[0] = 0;

        for i in 0..n - 1 {
            let step = nums[i] as usize;

            for j in 1..=step.min(n - i - 1) {
                dp[i + j] = dp[i + j].min(dp[i] + 1);
            }
        }

        dp[n - 1]
    }
}

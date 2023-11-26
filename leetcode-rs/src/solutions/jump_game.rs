use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    55,
    "Jump Game",
    [vec![2, 3, 1, 1, 4], vec![3, 2, 1, 0, 4], vec![1]],
    [true, false, true],
    Self::can_jump
);

impl SolutionImpl {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut dp = vec![false; n];
        dp[0] = true;

        for i in 0..n {
            if dp[i] {
                if i + nums[i] as usize >= n - 1 {
                    return true;
                }
                for j in 0..=nums[i] as usize {
                    if let Some(v) = dp.get_mut(i + j) {
                        *v = true;
                    }
                }
            } else {
                return false;
            }
        }

        false
    }
}

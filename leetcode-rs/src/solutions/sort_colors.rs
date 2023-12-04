use super::{mut_test_helper, Solution};

pub struct SolutionImpl;

crate::derive_inplace_solution!(
    SolutionImpl,
    75,
    "Sort Colors",
    [vec![2, 0, 2, 1, 1, 0], vec![2, 0, 1]],
    [vec![0, 0, 1, 1, 2, 2], vec![0, 1, 2]],
    Self::sort_colors
);

impl SolutionImpl {
    #[allow(clippy::ptr_arg)]
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let n = nums.len();
        if n == 0 {
            return;
        }
        for i in 0..n - 1 {
            for j in 0..n - i - 1 {
                if nums[j] > nums[j + 1] {
                    nums.swap(j, j + 1);
                }
            }
        }
    }
}

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    45,
    "Jump Game II",
    [vec![2, 3, 1, 1, 4], vec![2, 3, 0, 1, 4]],
    [2, 2],
    Self::jump
);

impl SolutionImpl {
    pub fn jump(nums: Vec<i32>) -> i32 {
        todo!()
    }
}

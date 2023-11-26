use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    55,
    "Jump Game",
    [vec![2, 3, 1, 1, 4], vec![3, 2, 1, 0, 4],],
    [true, false],
    Self::can_jump
);

impl SolutionImpl {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        todo!()
    }
}

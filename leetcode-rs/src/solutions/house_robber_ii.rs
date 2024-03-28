use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    213,
    "House Robber II",
    [vec![2, 3, 2], vec![1, 2, 3, 1], vec![1, 2, 3]],
    [3, 4, 5],
    Self::rob
);

impl SolutionImpl {
    pub fn rob(nums: Vec<i32>) -> i32 {
        todo!()
    }
}

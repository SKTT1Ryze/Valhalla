use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    229,
    "Majority Element II",
    [vec![3, 2, 3], vec![1], vec![1, 2]],
    [vec![3], vec![1], vec![1, 2]],
    Self::majority_element
);

impl SolutionImpl {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        todo!()
    }
}

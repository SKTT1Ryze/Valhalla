use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    217,
    "Contains Duplicate",
    [
        vec![1, 2, 3, 1],
        vec![1, 2, 3, 4],
        vec![1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
    ],
    [true, false, true],
    Self::contains_duplicate
);

impl SolutionImpl {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        todo!()
    }
}

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    81,
    "Search in Rotated Sorted Array II",
    [
        (vec![2, 5, 6, 0, 0, 1, 2], 0),
        (vec![2, 5, 6, 0, 0, 1, 2], 3)
    ],
    [true, false],
    |(nums, target)| Self::search(nums, target)
);

impl SolutionImpl {
    pub fn search(nums: Vec<i32>, target: i32) -> bool {
        todo!()
    }
}

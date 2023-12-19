use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    66,
    "Plus One",
    [vec![1, 2, 3], vec![4, 3, 2, 1], vec![9]],
    [vec![1, 2, 4], vec![4, 3, 2, 2], vec![1, 0]],
    Self::plus_one
);

impl SolutionImpl {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        todo!()
    }
}

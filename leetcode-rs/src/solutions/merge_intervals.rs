use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    56,
    "Merge Intervals",
    [
        vec![vec![1, 3], vec![2, 6], vec![8, 10], vec![15, 18]],
        vec![vec![1, 4], vec![4, 5]]
    ],
    [
        vec![vec![1, 6], vec![8, 10], vec![15, 18]],
        vec![vec![1, 5]]
    ],
    Self::merge
);

impl SolutionImpl {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        todo!()
    }
}

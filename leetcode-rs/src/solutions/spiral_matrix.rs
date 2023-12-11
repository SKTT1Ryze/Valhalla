use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    54,
    "Spiral Matrix",
    [
        vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]],
        vec![vec![1, 2, 3, 4], vec![5, 6, 7, 8], vec![9, 10, 11, 12]]
    ],
    [
        vec![1, 2, 3, 6, 9, 8, 7, 4, 5],
        vec![1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
    ],
    Self::spiral_order
);

impl SolutionImpl {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        todo!()
    }
}

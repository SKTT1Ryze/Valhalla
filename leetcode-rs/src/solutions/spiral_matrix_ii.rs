use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    59,
    "Spiral Matrix II",
    [3, 1],
    [
        vec![vec![1, 2, 3], vec![8, 9, 4], vec![7, 6, 5]],
        vec![vec![1]]
    ],
    Self::generate_matrix
);

impl SolutionImpl {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        todo!()
    }
}

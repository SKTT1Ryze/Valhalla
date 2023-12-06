use super::{mut_test_helper, Solution};

pub struct SolutionImpl;

crate::derive_inplace_solution!(
    SolutionImpl,
    73,
    "Set Matrix Zeroes",
    [
        vec![vec![1, 1, 1], vec![1, 0, 1], vec![1, 1, 1]],
        vec![vec![0, 1, 2, 0], vec![3, 4, 5, 2], vec![1, 3, 1, 5]]
    ],
    [
        vec![vec![1, 0, 1], vec![0, 0, 0], vec![1, 0, 1]],
        vec![vec![0, 0, 0, 0], vec![0, 4, 5, 0], vec![0, 3, 1, 0]]
    ],
    Self::set_zeroes
);

impl SolutionImpl {
    #[allow(clippy::ptr_arg)]
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        todo!()
    }
}

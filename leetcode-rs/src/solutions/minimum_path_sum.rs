use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    64,
    "Minimum Path Sum",
    [
        vec![vec![1, 3, 1], vec![1, 5, 1], vec![4, 2, 1]],
        vec![vec![1, 2, 3], vec![4, 5, 6]]
    ],
    [7, 12],
    Self::min_path_sum
);

impl SolutionImpl {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        todo!()
    }
}

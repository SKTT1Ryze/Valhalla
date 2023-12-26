use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    74,
    "Search a 2D Matrix",
    [
        (
            vec![vec![1, 3, 5, 7], vec![10, 11, 16, 20], vec![23, 30, 34, 60]],
            3
        ),
        (
            vec![vec![1, 3, 5, 7], vec![10, 11, 16, 20], vec![23, 30, 34, 60]],
            13
        )
    ],
    [true, false],
    |(matrix, target)| Self::search_matrix(matrix, target)
);

impl SolutionImpl {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        todo!()
    }
}

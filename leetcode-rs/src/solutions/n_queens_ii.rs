use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    52,
    "N-Queens II",
    [4, 2],
    [2, 1],
    Self::total_n_queens
);

impl SolutionImpl {
    pub fn total_n_queens(n: i32) -> i32 {
        todo!()
    }
}

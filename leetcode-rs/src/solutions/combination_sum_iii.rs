use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    216,
    "Combination Sum III",
    [(3, 7), (3, 9), (4, 1)],
    [
        vec![vec![1, 2, 4]],
        vec![vec![1, 2, 6], vec![1, 3, 5], vec![2, 3, 4]],
        vec![]
    ],
    |(k, n)| Self::combination_sum3(k, n)
);

impl SolutionImpl {
    pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {
        todo!()
    }
}

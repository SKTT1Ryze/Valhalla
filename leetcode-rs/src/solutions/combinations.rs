use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    77,
    "Combinations",
    [(4, 2), (1, 1)],
    [vec![
        vec![1, 2],
        vec![1, 3],
        vec![1, 4],
        vec![2, 3],
        vec![2, 4],
        vec![3, 4]
    ],],
    |(n, k)| Self::combine(n, k)
);

impl SolutionImpl {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        todo!()
    }
}

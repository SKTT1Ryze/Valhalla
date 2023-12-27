use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    78,
    "Subsets",
    [vec![1, 2, 3], vec![0],],
    [
        vec![
            vec![],
            vec![1],
            vec![2],
            vec![1, 2],
            vec![3],
            vec![1, 3],
            vec![2, 3],
            vec![1, 2, 3]
        ],
        vec![vec![], vec![0]]
    ],
    Self::subsets
);

impl SolutionImpl {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        todo!()
    }
}

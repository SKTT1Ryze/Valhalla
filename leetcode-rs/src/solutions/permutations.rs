use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    46,
    "Permutations",
    [vec![1, 2, 3], vec![0, 1], vec![1]],
    [
        vec![
            vec![1, 2, 3],
            vec![1, 3, 2],
            vec![2, 1, 3],
            vec![2, 3, 1],
            vec![3, 1, 2],
            vec![3, 2, 1]
        ],
        vec![vec![0, 1], vec![1, 0]],
        vec![vec![1]]
    ],
    |nums| {
        let mut output = Self::permute(nums);
        output.sort();
        output
    }
);

impl SolutionImpl {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        todo!()
    }
}

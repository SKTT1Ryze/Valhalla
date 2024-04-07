use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    221,
    "Maximal Square",
    [
        vec![
            vec!['1', '0', '1', '0', '0'],
            vec!['1', '0', '1', '1', '1'],
            vec!['1', '1', '1', '1', '1'],
            vec!['1', '0', '0', '1', '0']
        ],
        vec![vec!['0', '1'], vec!['1', '0']]
    ],
    [4, 1],
    Self::maximal_square
);

impl SolutionImpl {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        todo!()
    }
}

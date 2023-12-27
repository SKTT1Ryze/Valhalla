use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    79,
    "Word Search",
    [
        (
            vec![
                vec!['A', 'B', 'C', 'E'],
                vec!['S', 'F', 'C', 'S'],
                vec!['A', 'D', 'E', 'E']
            ],
            "ABCCED".to_string()
        ),
        (
            vec![
                vec!['A', 'B', 'C', 'E'],
                vec!['S', 'F', 'C', 'S'],
                vec!['A', 'D', 'E', 'E']
            ],
            "SEE".to_owned()
        )
    ],
    [true, true],
    |(board, word)| Self::exist(board, word)
);

impl SolutionImpl {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        todo!()
    }
}

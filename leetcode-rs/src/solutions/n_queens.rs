use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    51,
    "N-Queens",
    [4, 1],
    [
        vec![
            vec![".Q..", "...Q", "Q...", "..Q."],
            vec!["..Q.", "Q...", "...Q", ".Q.."]
        ],
        vec![vec!["Q"]]
    ]
    .into_iter()
    .map(|v| v
        .into_iter()
        .map(|v| v.into_iter().map(std::convert::Into::into).collect())
        .collect())
    .collect::<Vec<_>>(),
    Self::solve_n_queens
);

impl SolutionImpl {
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        todo!()
    }
}

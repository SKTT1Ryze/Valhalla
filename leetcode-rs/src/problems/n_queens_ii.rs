use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    52,
    Difficulty::Hard,
    Topic::Algorithms,
    "N-Queens II",
    "The n-queens puzzle is the problem of placing n queens on an n x n \
     chessboard such that no two queens attack each other. Given an integer \
     n, return the number of distinct solutions to the n-queens puzzle.",
    "Backtracking".into()
);

use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    37,
    Difficulty::Hard,
    Topic::Algorithms,
    "Sudoku Solver",
    "Write a program to solve a Sudoku puzzle by filling the empty cells.",
    "Array".into(),
    "Sudoku".into(),
    "Backtracking".into()
);

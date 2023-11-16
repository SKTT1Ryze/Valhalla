use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    36,
    Difficulty::Medium,
    Topic::Algorithms,
    "Valid Sudoku",
    "",
    "Array".into()
);

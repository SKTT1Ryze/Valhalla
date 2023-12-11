use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    54,
    Difficulty::Medium,
    Topic::Algorithms,
    "Spiral Matrix",
    "Given an m x n matrix, return all elements of the matrix in spiral order.",
    "Array".into(),
    "Matrix".into()
);

use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    59,
    Difficulty::Medium,
    Topic::Algorithms,
    "Spiral Matrix II",
    "Given a positive integer n, generate an n x n matrix filled with \
     elements from 1 to n2 in spiral order.",
    "Matrix".into()
);

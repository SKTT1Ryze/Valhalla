use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    73,
    Difficulty::Medium,
    Topic::Algorithms,
    "Set Matrix Zeroes",
    "Given an m x n integer matrix matrix, if an element is 0, set its entire \
     row and column to 0's.",
);

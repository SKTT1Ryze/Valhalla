use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    79,
    Difficulty::Medium,
    Topic::Algorithms,
    "Word Search",
    "Given an m x n grid of characters board and a string word, return true \
     if word exists in the grid.",
    "Matrix".into(),
    "Backtracking".into()
);

use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    221,
    Difficulty::Medium,
    Topic::Algorithms,
    "Maximal Square",
    "Given an m x n binary matrix filled with 0's and 1's, find the largest \
     square containing only 1's and return its area.",
    "DP".into()
);

use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    77,
    Difficulty::Medium,
    Topic::Algorithms,
    "Combinations",
    "Given two integers n and k, return all possible combinations of k \
     numbers chosen from the range [1, n].",
    "Array".into(),
    "Backtracking".into()
);

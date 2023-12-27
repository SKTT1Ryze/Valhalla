use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    78,
    Difficulty::Medium,
    Topic::Algorithms,
    "Subsets",
    "Given an integer array nums of unique elements, return all possible \
     subsets (power set).",
    "Array".into(),
    "Backtracking".into()
);

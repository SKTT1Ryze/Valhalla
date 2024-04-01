use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    217,
    Difficulty::Easy,
    Topic::Algorithms,
    "Contains Duplicate",
    "Given an integer array nums, return true if any value appears at least \
     twice in the array, and return false if every element is distinct.",
    "".into()
);

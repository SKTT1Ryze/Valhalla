use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    229,
    Difficulty::Medium,
    Topic::Algorithms,
    "Majority Element II",
    "Given an integer array of size n, find all elements that appear more \
     than ⌊ n/3 ⌋ times.",
    "Math".into()
);

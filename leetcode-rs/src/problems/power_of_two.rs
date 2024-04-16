use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    231,
    Difficulty::Easy,
    Topic::Algorithms,
    "Power of Two",
    "Given an integer n, return true if it is a power of two. Otherwise, \
     return false.",
    "Math".into()
);

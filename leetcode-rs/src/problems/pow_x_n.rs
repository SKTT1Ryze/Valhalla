use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    50,
    Difficulty::Medium,
    Topic::Algorithms,
    "Pow(x, n)",
    "Implement pow(x, n), which calculates x raised to the power n (i.e., xn).",
    "Math".into()
);

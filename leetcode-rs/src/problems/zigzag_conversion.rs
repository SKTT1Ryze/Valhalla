use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    6,
    Difficulty::Medium,
    Topic::Algorithms,
    "Zigzag Conversion",
    "",
    "String".into()
);

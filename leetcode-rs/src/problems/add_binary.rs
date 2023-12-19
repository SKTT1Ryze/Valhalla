use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    67,
    Difficulty::Easy,
    Topic::Algorithms,
    "Add Binary",
    "Given two binary strings a and b, return their sum as a binary string.",
    "String".into(),
    "Math".into()
);

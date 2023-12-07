use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    76,
    Difficulty::Hard,
    Topic::Algorithms,
    "Minimum Window Substring",
    "",
    "Hash Map".into(),
    "Two Pointer".into()
);

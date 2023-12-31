use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    44,
    Difficulty::Hard,
    Topic::Algorithms,
    "Wildcard Matching",
    "",
    "String".into(),
    "DP".into()
);

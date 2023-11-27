use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    62,
    Difficulty::Medium,
    Topic::Algorithms,
    "Unique Paths",
    "",
    "DP".into()
);

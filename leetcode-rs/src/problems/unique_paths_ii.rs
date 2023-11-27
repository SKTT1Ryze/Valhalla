use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    63,
    Difficulty::Medium,
    Topic::Algorithms,
    "Unique Paths II",
    "",
    "DP".into()
);

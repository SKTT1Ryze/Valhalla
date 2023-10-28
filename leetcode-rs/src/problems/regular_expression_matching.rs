use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    10,
    Difficulty::Hard,
    Topic::Algorithms,
    "Regular Expression Matching",
    "",
    "String".into(),
    "DP".into(),
    "Recursion".into()
);

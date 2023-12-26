use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    72,
    Difficulty::Medium,
    Topic::Algorithms,
    "Edit Distance",
    "Given two strings word1 and word2, return the minimum number of \
     operations required to convert word1 to word2.",
    "String".into(),
    "DP".into()
);

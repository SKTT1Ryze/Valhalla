use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    5,
    Difficulty::Medium,
    Topic::Algorithms,
    "Longest Palindromic Substring",
    r#"Given a string s, return the longest palindromic substring in s."#,
    "String".into(),
    "DP".into()
);

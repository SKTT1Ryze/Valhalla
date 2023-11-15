use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    32,
    Difficulty::Hard,
    Topic::Algorithms,
    "Longest Valid Parentheses",
    "Given a string containing just the characters '(' and ')', return the length of the longest \
     valid (well-formed) parentheses substring.",
    "Stack".into(),
    "DP".into()
);

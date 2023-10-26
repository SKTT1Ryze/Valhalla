use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    9,
    Difficulty::Easy,
    Topic::Algorithms,
    "Palindrome Number",
    "Given an integer x, return true if x is a palindrome, and false otherwise.",
    "Match".into()
);

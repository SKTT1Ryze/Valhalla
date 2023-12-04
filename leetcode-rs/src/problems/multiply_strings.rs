use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    43,
    Difficulty::Medium,
    Topic::Algorithms,
    "Multiply Strings",
    "Given two non-negative integers num1 and num2 represented as strings, \
     return the product of num1 and num2, also represented as a string.",
    "String".into(),
    "Math".into()
);

use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    8,
    Difficulty::Medium,
    Topic::Algorithms,
    "String to Integer (atoi)",
    "Implement the myAtoi(string s) function, which converts a string to a \
     32-bit signed integer (similar to C/C++'s atoi function).",
    "String".into()
);

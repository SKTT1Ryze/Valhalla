use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    7,
    Difficulty::Medium,
    Topic::Algorithms,
    "Reverse Integer",
    r#"Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0."#,
    "Math".into()
);

use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    1,
    Difficulty::Easy,
    Topic::Algorithms,
    "Two Sum",
    r#"Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.You can return the answer in any order."#,
    "Array".into(),
    "Hash Map".into()
);

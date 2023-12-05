use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    179,
    Difficulty::Medium,
    Topic::Algorithms,
    "Largest Number",
    "Given a list of non-negative integers nums, arrange them such that they \
     form the largest number and return it.",
    "Array".into(),
    "Greedy".into()
);

use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    57,
    Difficulty::Medium,
    Topic::Algorithms,
    "Insert Interval",
    "",
    "Array".into()
);

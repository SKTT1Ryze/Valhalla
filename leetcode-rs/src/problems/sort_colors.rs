use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    75,
    Difficulty::Medium,
    Topic::Algorithms,
    "Sort Colors",
    "",
    "Array".into(),
    "Two Pointer".into()
);

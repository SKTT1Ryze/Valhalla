use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    81,
    Difficulty::Medium,
    Topic::Algorithms,
    "Search in Rotated Sorted Array II",
    "",
    "Array".into(),
    "Binary Search".into()
);

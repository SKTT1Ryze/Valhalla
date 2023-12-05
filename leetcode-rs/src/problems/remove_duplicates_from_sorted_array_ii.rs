use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    80,
    Difficulty::Medium,
    Topic::Algorithms,
    "Remove Duplicates from Sorted Array II",
    "",
    "Array".into(),
    "Two Pointer".into()
);

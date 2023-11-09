use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    26,
    Difficulty::Easy,
    Topic::Algorithms,
    "Remove Duplicates from Sorted Array",
    "",
    "Array".into()
);

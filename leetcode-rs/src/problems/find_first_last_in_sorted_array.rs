use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    34,
    Difficulty::Medium,
    Topic::Algorithms,
    "Find First and Last Position of Element in Sorted Array",
    "",
    "Array".into()
);

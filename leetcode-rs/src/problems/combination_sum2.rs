use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    40,
    Difficulty::Medium,
    Topic::Algorithms,
    "Combination Sum II",
    "",
    "Array".into()
);

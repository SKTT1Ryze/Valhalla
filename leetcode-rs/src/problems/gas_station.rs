use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    134,
    Difficulty::Medium,
    Topic::Algorithms,
    "Gas Station",
    "",
    "Array".into(),
    "Greedy".into()
);

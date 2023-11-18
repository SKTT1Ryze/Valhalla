use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    39,
    Difficulty::Medium,
    Topic::Algorithms,
    "Combination Sum",
    "",
    "Array".into(),
    "Math".into()
);

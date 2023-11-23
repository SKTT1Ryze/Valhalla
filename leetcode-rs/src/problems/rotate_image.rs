use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    48,
    Difficulty::Medium,
    Topic::Algorithms,
    "Rotate Image",
    "",
    "Matrix".into(),
    "In Place".into()
);

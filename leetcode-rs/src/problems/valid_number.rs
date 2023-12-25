use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    65,
    Difficulty::Hard,
    Topic::Algorithms,
    "Valid Number",
    "",
    "Math".into()
);

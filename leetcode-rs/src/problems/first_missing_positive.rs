use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    41,
    Difficulty::Hard,
    Topic::Algorithms,
    "First Missing Positive",
    "",
    "Array".into()
);

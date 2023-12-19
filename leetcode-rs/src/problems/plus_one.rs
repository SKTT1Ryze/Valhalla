use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    66,
    Difficulty::Easy,
    Topic::Algorithms,
    "Plus One",
    "",
    "Array".into(),
    "Math".into()
);

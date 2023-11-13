use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    30,
    Difficulty::Hard,
    Topic::Algorithms,
    "Substring with Concatenation of All Words",
    "",
    "String".into(),
    "Array".into()
);

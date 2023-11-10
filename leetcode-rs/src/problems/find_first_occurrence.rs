use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    28,
    Difficulty::Easy,
    Topic::Algorithms,
    "Find the Index of the First Occurrence in a String",
    "",
    "String".into()
);

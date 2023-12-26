use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    74,
    Difficulty::Medium,
    Topic::Algorithms,
    "Search a 2D Matrix",
    "",
    "Matrix".into()
);

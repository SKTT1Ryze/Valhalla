use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    38,
    Difficulty::Medium,
    Topic::Algorithms,
    "Count and Say",
    "",
    "String".into()
);

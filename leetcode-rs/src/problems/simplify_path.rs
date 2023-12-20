use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    71,
    Difficulty::Medium,
    Topic::Algorithms,
    "Simplify Path",
    "",
    "String".into()
);

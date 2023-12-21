use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    51,
    Difficulty::Hard,
    Topic::Algorithms,
    "N-Queens",
    "",
    "Backtracking".into()
);

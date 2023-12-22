use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    60,
    Difficulty::Hard,
    Topic::Algorithms,
    "Permutation Sequence",
    "",
    "Math".into(),
    "Recursion".into()
);

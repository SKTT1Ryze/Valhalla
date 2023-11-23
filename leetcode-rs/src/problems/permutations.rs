use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    46,
    Difficulty::Medium,
    Topic::Algorithms,
    "Permutations",
    "",
    "Array".into()
);

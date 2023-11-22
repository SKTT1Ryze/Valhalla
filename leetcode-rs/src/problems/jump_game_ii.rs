use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    45,
    Difficulty::Medium,
    Topic::Algorithms,
    "Jump Game II",
    "",
    "Array".into()
);

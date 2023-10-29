use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    11,
    Difficulty::Medium,
    Topic::Algorithms,
    "Container With Most Water",
    "",
    "Array".into()
);

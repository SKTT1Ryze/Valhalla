use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    69,
    Difficulty::Easy,
    Topic::Algorithms,
    "Sqrt(x)",
    "Given a non-negative integer x, return the square root of x rounded down \
     to the nearest integer. The returned integer should be non-negative as \
     well.",
    "Math".into()
);

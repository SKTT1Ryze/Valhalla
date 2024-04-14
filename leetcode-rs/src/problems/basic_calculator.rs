use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    224,
    Difficulty::Hard,
    Topic::Algorithms,
    "Basic Calculator",
    "Given a string s representing a valid expression, implement a basic \
     calculator to evaluate it, and return the result of the evaluation.",
    "Math".into()
);

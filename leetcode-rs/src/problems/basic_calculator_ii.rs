use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    227,
    Difficulty::Medium,
    Topic::Algorithms,
    "Basic Calculator II",
    "Given a string s which represents an expression, evaluate this \
     expression and return its value. ",
    "Math".into()
);

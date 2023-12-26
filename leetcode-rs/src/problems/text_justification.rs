use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    68,
    Difficulty::Hard,
    Topic::Algorithms,
    "Text Justification",
    "Given an array of strings words and a width maxWidth, format the text \
     such that each line has exactly maxWidth characters and is fully (left \
     and right) justified.",
    "Array".into(),
    "String".into()
);

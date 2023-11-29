use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    61,
    Difficulty::Medium,
    Topic::Algorithms,
    "Rotate List",
    "Given the head of a linked list, rotate the list to the right by k places.",
    "Link List".into(),
    "Two Pointer".into()
);

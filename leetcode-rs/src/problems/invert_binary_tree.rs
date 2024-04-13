use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    226,
    Difficulty::Easy,
    Topic::Algorithms,
    "Invert Binary Tree",
    "Given the root of a binary tree, invert the tree, and return its root.",
    "Binary Tree".into()
);

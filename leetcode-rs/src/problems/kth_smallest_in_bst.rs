use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    230,
    Difficulty::Medium,
    Topic::Algorithms,
    "Kth Smallest Element in a BST",
    "Given the root of a binary search tree, and an integer k, return the kth \
     smallest value (1-indexed) of all the values of the nodes in the tree.",
    "Binary Tree".into()
);

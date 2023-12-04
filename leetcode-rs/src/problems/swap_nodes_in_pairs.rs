use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    24,
    Difficulty::Medium,
    Topic::Algorithms,
    "Swap Nodes in Pairs",
    "Given a linked list, swap every two adjacent nodes and return its head. \
     You must solve the problem without modifying the values in the list's \
     nodes",
    "Link List".into()
);

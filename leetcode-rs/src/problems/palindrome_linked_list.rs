use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    234,
    Difficulty::Easy,
    Topic::Algorithms,
    "Palindrome Linked List",
    "Given the head of a singly linked list, return true if it is a \
     palindrome or false otherwise.",
    "Linked List".into()
);

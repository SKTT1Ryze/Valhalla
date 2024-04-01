use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    219,
    Difficulty::Easy,
    Topic::Algorithms,
    "Contains Duplicate II",
    "Given an integer array nums and an integer k, return true if there are \
     two distinct indices i and j in the array such that nums[i] == nums[j] \
     and abs(i - j) <= k.",
    "".into()
);

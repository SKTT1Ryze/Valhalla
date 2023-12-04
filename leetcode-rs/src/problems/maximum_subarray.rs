use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    53,
    Difficulty::Medium,
    Topic::Algorithms,
    "Maximum Subarray",
    "Given an integer array nums, find the subarray with the largest sum, and \
     return its sum.",
    "Array".into(),
    "DP".into()
);

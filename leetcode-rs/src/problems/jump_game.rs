use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    55,
    Difficulty::Medium,
    Topic::Algorithms,
    "Jump Game",
    "You are given an integer array nums. You are initially positioned at the array's first \
     index, and each element in the array represents your maximum jump length at that position. \
     Return true if you can reach the last index, or false otherwise.",
    "Array".into(),
    "DP".into()
);

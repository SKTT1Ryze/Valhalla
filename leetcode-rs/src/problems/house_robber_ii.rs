use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    213,
    Difficulty::Medium,
    Topic::Algorithms,
    "House Robber II",
    "Given an integer array nums representing the amount of money of each \
     house, return the maximum amount of money you can rob tonight without \
     alerting the police.",
    "DP".into()
);

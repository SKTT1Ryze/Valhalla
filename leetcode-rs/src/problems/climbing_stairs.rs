use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    70,
    Difficulty::Medium,
    Topic::Algorithms,
    "Climbing Stairs",
    "You are climbing a staircase. It takes n steps to reach the top. Each time you can either \
     climb 1 or 2 steps. In how many distinct ways can you climb to the top?",
    "DP".into()
);

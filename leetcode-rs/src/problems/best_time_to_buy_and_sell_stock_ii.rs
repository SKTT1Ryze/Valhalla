use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    122,
    Difficulty::Medium,
    Topic::Algorithms,
    "Best Time to Buy and Sell Stock II",
    "",
    "Array".into(),
    "Greedy".into()
);

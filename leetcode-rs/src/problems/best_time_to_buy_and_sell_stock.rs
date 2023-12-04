use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    121,
    Difficulty::Easy,
    Topic::Algorithms,
    "Best Time to Buy and Sell Stock",
    "",
    "Array".into(),
    "Greedy".into()
);

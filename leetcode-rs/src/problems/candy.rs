use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    135,
    Difficulty::Hard,
    Topic::Algorithms,
    "Candy",
    "",
    "Array".into(),
    "Greedy".into()
);

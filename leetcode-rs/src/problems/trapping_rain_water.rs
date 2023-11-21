use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    42,
    Difficulty::Hard,
    Topic::Algorithms,
    "Trapping Rain Water",
    "",
    "Array".into(),
    "Two Pointer".into()
);

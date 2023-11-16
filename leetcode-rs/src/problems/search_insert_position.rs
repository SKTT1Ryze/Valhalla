use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    35,
    Difficulty::Easy,
    Topic::Algorithms,
    "Search Insert Position",
    "",
    "Array".into()
);

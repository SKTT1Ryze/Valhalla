use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    49,
    Difficulty::Medium,
    Topic::Algorithms,
    "Group Anagrams",
    "",
    "Array".into(),
    "String".into()
);

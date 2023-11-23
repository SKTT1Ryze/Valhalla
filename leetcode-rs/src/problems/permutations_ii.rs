use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    47,
    Difficulty::Medium,
    Topic::Algorithms,
    "Permutations II",
    "Given a collection of numbers, nums, that might contain duplicates, return all possible \
     unique permutations in any order.",
    "Array".into(),
    "Backtracking".into()
);

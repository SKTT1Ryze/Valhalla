use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    216,
    Difficulty::Medium,
    Topic::Algorithms,
    "Combination Sum III",
    "Return a list of all possible valid combinations. The list must not \
     contain the same combination twice, and the combinations may be returned \
     in any order.",
    "Backtracking".into()
);

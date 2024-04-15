use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    228,
    Difficulty::Easy,
    Topic::Algorithms,
    "Summary Ranges",
    "Return the smallest sorted list of ranges that cover all the numbers in \
     the array exactly.",
    "Math".into()
);

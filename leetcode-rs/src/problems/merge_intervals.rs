use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    56,
    Difficulty::Medium,
    Topic::Algorithms,
    "Merge Intervals",
    "Given an array of intervals where intervals[i] = [starti, endi], merge \
     all overlapping intervals, and return an array of the non-overlapping \
     intervals that cover all the intervals in the input.",
    "Array".into()
);

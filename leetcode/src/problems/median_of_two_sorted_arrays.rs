use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    4,
    Difficulty::Hard,
    Topic::Algorithms,
    "Median of Two Sorted Arrays",
    r#"Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n))."#,
    "Array".into()
);

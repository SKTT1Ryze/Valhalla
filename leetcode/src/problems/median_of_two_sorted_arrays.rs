use super::{Difficulty, Problem, Topic};

pub struct MedianOfTwoSortedArrays;

impl Problem for MedianOfTwoSortedArrays {
    fn id(&self) -> usize {
        4
    }
    fn difficulty(&self) -> Difficulty {
        Difficulty::Hard
    }
    fn topic(&self) -> Topic {
        Topic::Algorithms
    }
    fn title(&self) -> String {
        "Median of Two Sorted Arrays".into()
    }
    fn description(&self) -> String {
        r#"Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n))."#.into()
    }
    fn labels(&self) -> Vec<String> {
        ["Array".into()].into()
    }
}

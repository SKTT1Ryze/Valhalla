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
        todo!()
    }
    fn labels(&self) -> Vec<String> {
        ["Array".into()].into()
    }
}

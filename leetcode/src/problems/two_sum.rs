use super::{Difficulty, Problem, Topic};

pub struct TwoSum;

impl Problem for TwoSum {
    fn id(&self) -> usize {
        1
    }
    fn difficulty(&self) -> Difficulty {
        Difficulty::Easy
    }
    fn topic(&self) -> Topic {
        Topic::Algorithms
    }
    fn title(&self) -> String {
        "Two Sum".into()
    }
    fn description(&self) -> String {
        r#"Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.You can return the answer in any order."#
        .into()
    }
    fn labels(&self) -> Vec<String> {
        ["array".into(), "hashmap".into()].into()
    }
}

use super::{Difficulty, Problem, Topic};

pub struct LongestSubstring;

impl Problem for LongestSubstring {
    fn id(&self) -> usize {
        3
    }
    fn difficulty(&self) -> Difficulty {
        Difficulty::Medium
    }
    fn topic(&self) -> Topic {
        Topic::Algorithms
    }
    fn title(&self) -> String {
        "Longest Substring Without Repeating Characters".into()
    }
    fn description(&self) -> String {
        r#"Given a string s, find the length of the longest 
substring without repeating characters.
"#
        .into()
    }
    fn labels(&self) -> Vec<String> {
        ["String".into(), "Hash Map".into()].into()
    }
}

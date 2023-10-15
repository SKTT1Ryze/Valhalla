use super::{Difficulty, Problem, Topic};

pub struct LongestPalindromicSubstring;

impl Problem for LongestPalindromicSubstring {
    fn id(&self) -> usize {
        5
    }
    fn difficulty(&self) -> Difficulty {
        Difficulty::Medium
    }
    fn topic(&self) -> Topic {
        Topic::Algorithms
    }
    fn title(&self) -> String {
        "Longest Palindromic Substring".into()
    }
    fn description(&self) -> String {
        r#"Given a string s, return the longest palindromic substring in s."#.into()
    }
    fn labels(&self) -> Vec<String> {
        ["String".into(), "DP".into()].into()
    }
}

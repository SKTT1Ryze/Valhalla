use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    3,
    Difficulty::Medium,
    Topic::Algorithms,
    "Longest Substring Without Repeating Characters",
    r#"Given a string s, find the length of the longest 
substring without repeating characters.
"#,
    "String".into(),
    "Hash Map".into()
);

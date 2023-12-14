use super::{Difficulty, Problem, Topic};

pub struct ProblemImpl;

crate::derive_problem!(
    ProblemImpl,
    58,
    Difficulty::Easy,
    Topic::Algorithms,
    "Length of Last Word",
    "Given a string s consisting of words and spaces, return the length of \
     the last word in the string. A word is a maximal substring consisting of \
     non-space characters only.",
    "String".into()
);

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    68,
    "Text Justification",
    [
        (
            vec![
                "This",
                "is",
                "an",
                "example",
                "of",
                "text",
                "justification."
            ],
            16
        ),
        (
            vec!["What", "must", "be", "acknowledgment", "shall", "be"],
            16
        ),
        (
            vec![
                "Science",
                "is",
                "what",
                "we",
                "understand",
                "well",
                "enough",
                "to",
                "explain",
                "to",
                "a",
                "computer.",
                "Art",
                "is",
                "everything",
                "else",
                "we",
                "do"
            ],
            20
        ),
    ],
    [
        vec!["This    is    an", "example  of text", "justification.  "],
        vec!["What   must   be", "acknowledgment  ", "shall be        "],
        vec![
            "Science  is  what we",
            "understand      well",
            "enough to explain to",
            "a  computer.  Art is",
            "everything  else  we",
            "do                  "
        ]
    ]
    .into_iter()
    .map(|v| v.into_iter().map(std::convert::Into::into).collect()),
    |(words, max_width)| {
        let words = words.into_iter().map(std::convert::Into::into).collect();
        Self::full_justify(words, max_width)
    }
);

impl SolutionImpl {
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        todo!()
    }
}

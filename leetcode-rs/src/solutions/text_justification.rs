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
        // ref: https://leetcode.com/problems/text-justification/solutions/3952119/94-14-2-approaches-greedy/
        let mut res = Vec::new();
        let mut cur = Vec::new();
        let mut num_of_letters: i32 = 0;

        for word in &words {
            if word.len() as i32 + cur.len() as i32 + num_of_letters > max_width
            {
                for i in 0..(max_width - num_of_letters) {
                    let idx = i as usize
                        % (if cur.len() > 1 {
                            cur.len() - 1
                        } else {
                            cur.len()
                        });
                    cur[idx] = format!("{} ", cur[idx]);
                }
                res.push(cur.join(""));
                cur.clear();
                num_of_letters = 0;
            }
            cur.push(word.clone());
            num_of_letters += word.len() as i32;
        }

        let last_line = cur.join(" ");
        res.push(format!("{:<width$}", last_line, width = max_width as usize));

        res
    }
}

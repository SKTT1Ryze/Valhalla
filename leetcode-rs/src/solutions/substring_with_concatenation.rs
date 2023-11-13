use std::collections::HashMap;

use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Substring with Concatenation of All Words".into()
    }
    fn problem_id(&self) -> usize {
        30
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            (
                "barfoothefoobarman",
                vec!["foo".into(), "bar".into()],
                vec![0, 9],
            ),
            (
                "wordgoodgoodgoodbestword",
                vec!["word".into(), "good".into(), "best".into(), "word".into()],
                vec![],
            ),
            (
                "barfoofoobarthefoobarman",
                vec!["bar".into(), "foo".into(), "the".into()],
                vec![6, 9, 12],
            ),
            (
                "wordgoodgoodgoodbestword",
                vec!["word".into(), "good".into(), "best".into(), "good".into()],
                vec![8],
            ),
            ("a", vec!["a".into(), "a".into()], vec![]),
        ];

        for (s, words, expect) in testcases {
            let output = Self::find_substring(s.into(), words.clone());

            if output != expect {
                anyhow::bail!(
                    "test failed for s={s}, words={words:?}, expect={expect:?}, output={output:?}"
                );
            }
        }

        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

impl SolutionImpl {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        if words.is_empty() {
            return vec![];
        }
        let word_len = words[0].len();
        let len = word_len * words.len();
        if s.len() < len {
            return vec![];
        }

        let mut map: HashMap<String, usize> = HashMap::new();
        for word in &words {
            *map.entry(word.to_owned()).or_default() += 1;
        }

        let mut res = Vec::new();
        let mut start = 0;

        while start <= s.len().wrapping_sub(len) {
            let mut map_cloned = map.clone();
            let mut head = start;
            let mut tail = head + word_len;

            while tail <= s.len() {
                if let Some(val) = map_cloned.get_mut(&s[head..tail]) {
                    if *val == 1 {
                        map_cloned.remove(&s[head..tail]);
                    } else {
                        *val -= 1;
                    }
                } else {
                    break;
                }

                head += word_len;
                tail += word_len;
            }

            if map_cloned.is_empty() {
                res.push(start as i32);
            }

            start += 1;
        }

        res
    }
}

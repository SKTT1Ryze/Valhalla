use super::Solution;

pub struct LongestSubstring;

impl Solution for LongestSubstring {
    fn name(&self) -> String {
        "Solution for Longest Substring Without Repeating Characters".into()
    }
    fn problem_id(&self) -> usize {
        3
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases: Vec<(String, i32)> = vec![
            ("abcabcbb".into(), 3),
            ("bbbbb".into(), 1),
            ("pwwkew".into(), 3),
        ];

        for (input, expect) in testcases {
            let output = Self::length_of_longest_substring(input.clone());

            if output != expect {
                anyhow::bail!("test failed for input={input}, expect={expect}, output={output}");
            }
        }
        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

impl LongestSubstring {
    pub fn length_of_longest_substring(s: String) -> i32 {
        todo!()
    }
}

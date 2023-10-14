use std::collections::HashMap;

use super::Solution;

pub struct LongestSubstring;

const TESTCASES: [(&str, i32); 3] = [("abcabcbb", 3), ("bbbbb", 1), ("pwwkew", 3)];

impl Solution for LongestSubstring {
    fn name(&self) -> String {
        "Solution for Longest Substring Without Repeating Characters".into()
    }
    fn problem_id(&self) -> usize {
        3
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        for (input, expect) in TESTCASES {
            let output = Self::length_of_longest_substring(input.to_string());

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
        let chars: Vec<char> = s.chars().collect();
        let len = chars.len();

        if len <= 1 {
            return len as i32;
        }

        let mut max = 1;
        let mut head = 0;

        while head < len - 1 {
            let mut tail = head + 1;
            while tail < len {
                if !chars[head..tail].contains(&chars[tail]) {
                    tail += 1;
                } else {
                    break;
                }
                max = max.max(chars[head..tail].len());
            }
            head += 1;
        }

        max as i32
    }
}

pub struct LongestSubstringHashMap;

impl Solution for LongestSubstringHashMap {
    fn name(&self) -> String {
        "Solution for Longest Substring Without Repeating Characters using HashMap".into()
    }
    fn problem_id(&self) -> usize {
        3
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        for (input, expect) in TESTCASES {
            let output = Self::length_of_longest_substring(input.to_string());

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

impl LongestSubstringHashMap {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut max = 0usize;

        // [1] longest substring is the one with the largest
        //    difference between positions of repeated characters;
        //    thus, we should create a storage for such positions
        let mut map: HashMap<char, usize> = HashMap::new();

        // [2] while iterating through the string (i.e., moving
        //    the end of the sliding window), we should also
        //    update the start of the window
        let mut start = 0;

        for (end, ch) in s.chars().enumerate() {
            // [3] get the position for the start of sliding window
            //     with no other occurences of 'ch' in it
            start = map.get(&ch).copied().unwrap_or_default().max(start);

            // [4] update maximum length
            max = (end - start + 1).max(max);

            // [5] set the position to be used in [3] on next iterations
            map.insert(ch, end + 1);
        }

        max as i32
    }
}

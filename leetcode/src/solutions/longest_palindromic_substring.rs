use super::Solution;
use std::collections::HashMap;

pub struct LongestPalindromicSubstring;

impl Solution for LongestPalindromicSubstring {
    fn name(&self) -> String {
        "Solution for Longest Palindromic Substring".into()
    }
    fn problem_id(&self) -> usize {
        5
    }
    fn location(&self) -> String {
        crate::location!()
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [("babad", "bab"), ("cbbd", "bb")];

        for (input, expect) in testcases {
            let output = Self::longest_palindrome(input.into());

            if expect != output {
                anyhow::bail!("test failed for input={input}, expect={expect}, output={output}");
            }
        }

        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        todo!()
    }
}

impl LongestPalindromicSubstring {
    pub fn longest_palindrome(s: String) -> String {
        let mut max = "";
        let mut map: HashMap<char, Vec<_>> = HashMap::new();

        for (end, ch) in s.chars().enumerate() {
            map.entry(ch).or_default().push(end);

            for &start in map.get(&ch).unwrap_or(&vec![]) {
                let subs = &s[start..end + 1];

                if Self::check_palindromic(subs) {
                    if subs.len() > max.len() {
                        max = subs;
                    }
                    break;
                }
            }
        }

        max.into()
    }

    fn check_palindromic(s: &str) -> bool {
        let chars: Vec<_> = s.chars().collect();
        let len = chars.len();
        let mut p1 = 0;
        let mut p2 = len - 1;

        while p1 < p2 {
            if chars[p1] != chars[p2] {
                return false;
            }
            p1 += 1;
            p2 -= 1;
        }

        true
    }
}

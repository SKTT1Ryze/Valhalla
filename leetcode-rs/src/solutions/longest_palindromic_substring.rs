use super::Solution;
use std::collections::HashMap;

const TEST_CASES: [(&str, &str); 3] = [("babad", "bab"), ("cbbd", "bb"), ("aaaaa", "aaaaa")];

pub struct SolutionImpl;

impl Solution for SolutionImpl {
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
        for (input, expect) in TEST_CASES {
            let output = Self::longest_palindrome(input.into());

            if expect != output {
                anyhow::bail!("test failed for input={input}, expect={expect}, output={output}");
            }
        }

        Ok(())
    }
}

impl SolutionImpl {
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

pub struct SolutionImplDP;

impl Solution for SolutionImplDP {
    fn name(&self) -> String {
        "Solution for Longest Palindromic Substring with Dynamic Programming".into()
    }
    fn problem_id(&self) -> usize {
        5
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        for (input, expect) in TEST_CASES {
            let output = Self::longest_palindrome(input.into());

            if expect != output {
                anyhow::bail!("test failed for input={input}, expect={expect}, output={output}");
            }
        }

        Ok(())
    }
}

impl SolutionImplDP {
    pub fn longest_palindrome(s: String) -> String {
        let chars: Vec<char> = s.chars().collect();
        let len = chars.len();
        let mut result = "";
        let mut dp = vec![vec![false; len]; len];

        for (i, row) in dp.iter_mut().enumerate() {
            row[i] = true;
        }

        for (i, row) in dp.iter_mut().enumerate().take(len - 1) {
            row[i + 1] = chars[i] == chars[i + 1];
        }

        for diff in 0..len {
            for i in 0..len - diff {
                let j = i + diff;

                if j - i > 1 {
                    dp[i][j] = dp[i + 1][j - 1] && chars[i] == chars[j];
                }

                if dp[i][j] && j - i + 1 > result.len() {
                    result = &s[i..j + 1];
                }
            }
        }

        result.into()
    }
}

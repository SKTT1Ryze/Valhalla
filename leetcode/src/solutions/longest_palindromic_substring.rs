use super::Solution;

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
        todo!()
    }
}

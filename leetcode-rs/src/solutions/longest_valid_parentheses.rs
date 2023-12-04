use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Solution for Longest Valid Parentheses".into()
    }
    fn problem_id(&self) -> usize {
        32
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            ("(()", 2),
            (")()())", 4),
            ("", 0),
            ("()(())", 6),
            ("(())()(()((", 6),
            (")(((((()())()()))()(()))(", 22),
        ];

        for (s, expect) in testcases {
            let output = Self::longest_valid_parentheses(s.into());

            if output != expect {
                anyhow::bail!(
                    "test failed for s={s}, expect={expect}, output={output}"
                );
            }
        }
        Ok(())
    }
}

impl SolutionImpl {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let s: Vec<_> = s.chars().collect();
        let len = s.len();
        if len < 2 {
            return 0;
        }
        let mut dp = vec![0; len];
        let mut res = 0;

        for i in 1..len {
            if s[i] == ')' {
                if s[i - 1] == '(' {
                    dp[i] = if i >= 2 { dp[i - 2] } else { 0 } + 2;
                } else if i as i32 - dp[i - 1] > 0
                    && s[(i as i32 - dp[i - 1] - 1) as usize] == '('
                {
                    dp[i] = dp[i - 1]
                        + 2
                        + if i as i32 - dp[i - 1] - 2 >= 0 {
                            dp[(i as i32 - dp[i - 1] - 2) as usize]
                        } else {
                            0
                        };
                }
            }

            res = res.max(dp[i]);
        }

        res
    }
}

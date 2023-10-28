use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Solution for Regular Expression Matching".into()
    }
    fn problem_id(&self) -> usize {
        10
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            ("aa", "a", false),
            ("aa", "a*", true),
            ("ab", ".*", true),
            ("aab", "c*a*b", true),
            ("ab", ".*c", false),
        ];

        for (s, p, expect) in testcases {
            let output = Self::is_match(s.into(), p.into());

            if output != expect {
                anyhow::bail!("test failed for s={s}, p={p}, expect={expect}, output={output}");
            }
        }

        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

#[derive(Clone, Copy, PartialEq, Eq)]
enum State {
    Unknown,
    True,
    False,
}

impl SolutionImpl {
    pub fn is_match(s: String, p: String) -> bool {
        let mut dp = vec![vec![State::Unknown; p.len() + 1]; s.len() + 1];
        let s: Vec<_> = s.chars().collect();
        let p: Vec<_> = p.chars().collect();

        Self::r#match(&mut dp, 0, 0, &s, &p)
    }

    fn r#match(dp: &mut Vec<Vec<State>>, i: usize, j: usize, s: &[char], p: &[char]) -> bool {
        if dp[i][j] != State::Unknown {
            return dp[i][j] == State::True;
        }
        let ans;
        if j == p.len() {
            ans = i == s.len();
        } else {
            let first_match = i < s.len() && (s[i] == p[j] || p[j] == '.');

            if j < p.len() - 1 && p[j + 1] == '*' {
                ans = Self::r#match(dp, i, j + 2, s, p)
                    || first_match && Self::r#match(dp, i + 1, j, s, p);
            } else {
                ans = first_match && Self::r#match(dp, i + 1, j + 1, s, p);
            }
        }

        dp[i][j] = if ans { State::True } else { State::False };
        return ans;
    }
}

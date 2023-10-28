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

impl SolutionImpl {
    pub fn is_match(s: String, p: String) -> bool {
        let len = p.len();

        for i in 0..len {
            for j in i + 1..len + 1 {
                if Self::is_full_match(&s, &p[i..j]) {
                    return true;
                }
            }
        }

        false
    }

    fn is_full_match(s: &str, p: &str) -> bool {
        let mut i = 0;
        let mut j = 0;
        let s: Vec<char> = s.chars().collect();
        let p: Vec<char> = p.chars().collect();

        while i < s.len() {
            if !Self::recursion_match(&s, &p, i, &mut j) {
                return false;
            } else {
                i += 1;
            }
        }

        true
    }

    fn recursion_match(s: &[char], p: &[char], i: usize, j: &mut usize) -> bool {
        let ch_x = s[i];
        if let Some(&ch_p) = p.get(*j) {
            match ch_p {
                '.' => {
                    *j += 1;
                    true
                }
                '*' => {
                    if let Some(&prev) = p.get(j.wrapping_sub(1)) {
                        if ch_x == prev || prev == '.' {
                            true
                        } else if let Some(_) = p.get(*j + 1) {
                            *j += 1;
                            Self::recursion_match(s, p, i, j)
                        } else {
                            false
                        }
                    } else {
                        false
                    }
                }
                _ => {
                    *j += 1;
                    ch_x == ch_p
                }
            }
        } else {
            false
        }
    }
}

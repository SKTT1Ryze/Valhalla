use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Solution for String to Integer".into()
    }
    fn problem_id(&self) -> usize {
        8
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            ("42", 42),
            ("   -42", -42),
            ("4193 with words", 4193),
            ("    10522545459", 2147483647),
        ];

        for (s, expect) in testcases {
            let output = Self::my_atoi(s.to_string());

            if output != expect {
                anyhow::bail!("test failed for s={s}, expect={expect}, output={output}");
            }
        }

        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

#[derive(PartialEq, PartialOrd)]
enum State {
    BeforePositive,
    Positive,
    Digit,
}

impl SolutionImpl {
    pub fn my_atoi(s: String) -> i32 {
        let mut state = State::BeforePositive;
        let mut positive = true;
        let mut v = Vec::new();

        for ch in s.chars() {
            match ch {
                '-' | '+' => {
                    if state == State::BeforePositive {
                        positive = ch == '+';
                        state = State::Positive;
                    } else {
                        break;
                    }
                }
                '0'..='9' => {
                    if state != State::Digit {
                        state = State::Digit;
                    }

                    if ch == '0' && v.is_empty() {
                        continue;
                    }

                    v.push(ch as i32 - 48);
                }
                ' ' => {
                    if state != State::BeforePositive {
                        break;
                    }
                    // or ignore
                }
                _ => {
                    if state == State::Digit {
                        break;
                    } else {
                        return 0;
                    }
                }
            }
        }

        let mut acc = 0;
        for (p, e) in v.into_iter().rev().enumerate() {
            acc = Self::cal_overflow(acc, e, p, positive).unwrap_or(if positive {
                i32::MAX
            } else {
                i32::MIN
            });
        }

        acc
    }
    fn cal_overflow(acc: i32, e: i32, p: usize, positive: bool) -> Option<i32> {
        let pow = 10_i32.checked_pow(p as u32)?;
        let pow = e.checked_mul(pow)?;
        if positive {
            acc.checked_add(pow)
        } else {
            acc.checked_sub(pow)
        }
    }
}

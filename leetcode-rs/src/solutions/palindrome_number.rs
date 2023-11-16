use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Solution for Palindrome Number".into()
    }
    fn problem_id(&self) -> usize {
        9
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [(121, true), (-121, false), (10, false)];

        for (x, expect) in testcases {
            let output = Self::is_palindrome(x);

            if output != expect {
                anyhow::bail!("test failed for x={x}, output={output}, expect={expect}");
            }
        }

        Ok(())
    }
}

impl SolutionImpl {
    pub fn is_palindrome(mut x: i32) -> bool {
        if x < 0 {
            false
        } else if x < 10 {
            true
        } else {
            let mut v = Vec::new();
            while x > 0 {
                let residue = x % 10;
                x /= 10;

                v.push(residue);
            }

            let mut start = 0;
            let mut end = v.len() - 1;

            while start < end {
                if v[start] != v[end] {
                    return false;
                }

                start += 1;
                end -= 1;
            }

            true
        }
    }
}

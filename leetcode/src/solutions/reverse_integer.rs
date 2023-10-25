use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Solution for Reverse Integer".into()
    }
    fn problem_id(&self) -> usize {
        7
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [(123, 321), (-123, -321), (120, 21), (1534236469, 0)];

        for (x, expect) in testcases {
            let output = Self::reverse(x);

            if output != expect {
                anyhow::bail!("test failed for x={x}, expect={expect}, output={output}");
            }
        }

        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

impl SolutionImpl {
    pub fn reverse(mut x: i32) -> i32 {
        let flag = x >= 0;
        if !flag {
            x = -x;
        }
        let mut residue;
        let mut v = Vec::new();

        while x != 0 {
            residue = x % 10;
            x = x / 10;

            v.push(residue);
        }
        let mut acc: i32 = 0;

        for (p, e) in v.into_iter().rev().enumerate() {
            if let Some(val) = Self::cal_overflow(acc, e, p) {
                acc = val;
            } else {
                return 0;
            }
        }

        if flag {
            acc
        } else {
            -acc
        }
    }

    fn cal_overflow(acc: i32, e: i32, p: usize) -> Option<i32> {
        acc.checked_add(e.checked_mul(10_i32.pow(p as u32))?)
    }
}

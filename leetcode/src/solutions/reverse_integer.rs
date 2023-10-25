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
        let testcases = [(123, 321), (-123, -321), (120, 21)];

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
    pub fn reverse(x: i32) -> i32 {
        todo!()
    }
}

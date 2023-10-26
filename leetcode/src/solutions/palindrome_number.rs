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
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

impl SolutionImpl {
    pub fn is_palindrome(x: i32) -> bool {
        todo!()
    }
}

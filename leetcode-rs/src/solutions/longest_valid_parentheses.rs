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
        let testcases = [("(()", 2), (")()())", 4), ("", 0)];

        for (s, expect) in testcases {
            let output = Self::longest_valid_parentheses(s.into());

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

impl SolutionImpl {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        todo!()
    }
}

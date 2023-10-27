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
        let testcases = [("aa", "a", false), ("aa", "a*", true), ("ab", ".*", true)];

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
        todo!()
    }
}

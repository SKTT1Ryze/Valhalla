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
        let testcases = [("42", 42), ("   -42", -42), ("4193 with words", 4193)];

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

impl SolutionImpl {
    pub fn my_atoi(s: String) -> i32 {
        todo!()
    }
}

use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Container With Most Water".into()
    }
    fn problem_id(&self) -> usize {
        11
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [(vec![1, 8, 6, 2, 5, 4, 8, 3, 7], 49), (vec![1, 1], 1)];

        for (height, expect) in testcases {
            let output = Self::max_area(height.clone());

            if output != expect {
                anyhow::bail!(
                    "test failed for height={height:?}, expect={expect}, output={output}"
                );
            }
        }

        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

impl SolutionImpl {
    pub fn max_area(height: Vec<i32>) -> i32 {
        todo!()
    }
}

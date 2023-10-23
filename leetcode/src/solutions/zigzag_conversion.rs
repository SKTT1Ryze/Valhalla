use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Solution for Zigzag Conversion".into()
    }
    fn problem_id(&self) -> usize {
        6
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            ("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),
            ("PAYPALISHIRING", 4, "PINALSIGYAHRPI"),
            ("A", 1, "A"),
        ];

        for (s, num_rows, expect) in testcases {
            let output = Self::convert(s.into(), num_rows);

            if output != expect {
                anyhow::bail!(
                    "test failed for s={s}, num_rows={num_rows}, expect={expect}, output={output}"
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
    pub fn convert(s: String, num_rows: i32) -> String {
        todo!()
    }
}

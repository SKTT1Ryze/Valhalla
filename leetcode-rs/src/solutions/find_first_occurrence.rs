use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Find the Index of the First Occurrence in a String".into()
    }
    fn problem_id(&self) -> usize {
        28
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [("sadbutsad", "sad", 0), ("leetcode", "leeto", -1)];

        for (haystack, needle, expect) in testcases {
            let output = Self::str_str(haystack.into(), needle.into());

            if output != expect {
                anyhow::bail!(
                    "test failed for haystack={haystack}, needle={needle}, expect={expect}, \
                     output={output}"
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
    pub fn str_str(haystack: String, needle: String) -> i32 {
        todo!()
    }
}

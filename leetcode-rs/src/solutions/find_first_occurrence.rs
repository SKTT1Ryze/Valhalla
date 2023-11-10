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
        let testcases = [
            ("sadbutsad", "sad", 0),
            ("leetcode", "leeto", -1),
            ("mississippi", "issip", 4),
            ("mississippi", "pi", 9),
        ];

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
        let haystack: Vec<char> = haystack.chars().collect();
        let needle: Vec<char> = needle.chars().collect();
        let mut p1 = 0usize;
        let mut p2 = 0usize;
        let mut res = -1;

        while p1 < haystack.len() {
            if haystack[p1] == needle[p2] {
                p2 += 1;
            } else if p2 > 0 {
                p1 -= p2;
                p2 = 0;
            }

            if p2 == needle.len() {
                res = (p1 + 1 - p2) as i32;
                break;
            }

            p1 += 1;
        }

        res
    }
}

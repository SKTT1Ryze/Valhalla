use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Substring with Concatenation of All Words".into()
    }
    fn problem_id(&self) -> usize {
        30
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            (
                "barfoothefoobarman",
                vec!["foo".into(), "bar".into()],
                vec![0, 9],
            ),
            (
                "wordgoodgoodgoodbestword",
                vec!["word".into(), "good".into(), "best".into(), "word".into()],
                vec![],
            ),
            (
                "barfoofoobarthefoobarman",
                vec!["bar".into(), "foo".into(), "the".into()],
                vec![6, 9, 12],
            ),
        ];

        for (s, words, expect) in testcases {
            let output = Self::find_substring(s.into(), words.clone());

            if output != expect {
                anyhow::bail!(
                    "test failed for s={s}, words={words:?}, expect={expect:?}, output={output:?}"
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
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        todo!()
    }
}

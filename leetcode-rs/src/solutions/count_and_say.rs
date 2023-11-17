use super::{test_helper, Solution};

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Count and Say".into()
    }
    fn problem_id(&self) -> usize {
        38
    }
    fn location(&self) -> String {
        crate::location!()
    }
    fn test(&self) -> anyhow::Result<()> {
        test_helper([1, 4], ["1".into(), "1211".into()], Self::count_and_say)
    }
}

impl SolutionImpl {
    pub fn count_and_say(n: i32) -> String {
        todo!()
    }
}

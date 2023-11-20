use super::{test_helper, Solution};

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Solution for First Missing Positive".into()
    }
    fn problem_id(&self) -> usize {
        41
    }
    fn location(&self) -> String {
        crate::location!()
    }
    fn test(&self) -> anyhow::Result<()> {
        test_helper(
            [vec![1, 2, 0], vec![3, 4, -1, 1], vec![7, 8, 9, 11, 12]],
            [3, 2, 1],
            Self::first_missing_positive,
        )
    }
}

impl SolutionImpl {
    pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
        todo!()
    }
}

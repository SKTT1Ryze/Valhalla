use super::{test_helper, Solution};

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Search Insert Position".into()
    }
    fn problem_id(&self) -> usize {
        35
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        test_helper(
            [
                (vec![1, 3, 5, 6], 5),
                (vec![1, 3, 5, 6], 2),
                (vec![1, 3, 5, 6], 7),
            ],
            [2, 1, 4],
            |(nums, target)| Self::search_insert(nums, target),
        )
    }
}

impl SolutionImpl {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        todo!()
    }
}

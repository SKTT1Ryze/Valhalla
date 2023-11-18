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
        test_helper(
            [(vec![2, 3, 5], 8), (vec![2], 1)],
            [vec![vec![2, 2, 2, 2], vec![2, 3, 3], vec![3, 5]], vec![]],
            |(candidates, target)| Self::combination_sum(candidates, target),
        )
    }
}

impl SolutionImpl {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        todo!()
    }
}

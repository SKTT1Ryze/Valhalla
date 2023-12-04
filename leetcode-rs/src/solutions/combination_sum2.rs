use super::{test_helper, Solution};

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Count and Say".into()
    }
    fn problem_id(&self) -> usize {
        40
    }
    fn location(&self) -> String {
        crate::location!()
    }
    fn test(&self) -> anyhow::Result<()> {
        test_helper(
            [
                (vec![10, 1, 2, 7, 6, 1, 5], 8),
                (vec![2, 5, 2, 1, 2], 5),
                (
                    vec![
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1,
                    ],
                    27,
                ),
                (
                    vec![
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    ],
                    30,
                ),
            ],
            [
                vec![vec![1, 1, 6], vec![1, 2, 5], vec![1, 7], vec![2, 6]],
                vec![vec![1, 2, 2], vec![5]],
                vec![],
                vec![vec![
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                ]],
            ],
            |(candidates, target)| {
                let mut output = Self::combination_sum2(candidates, target);
                output.sort();
                output
            },
        )
    }
}

impl SolutionImpl {
    pub fn combination_sum2(
        mut candidates: Vec<i32>,
        target: i32,
    ) -> Vec<Vec<i32>> {
        let mut ans = Vec::new();
        candidates.sort();
        Self::backtrack(0, target, &mut Vec::new(), &candidates, &mut ans);
        ans
    }

    fn backtrack(
        start: usize,
        target: i32,
        path: &mut Vec<i32>,
        candidates: &Vec<i32>,
        result: &mut Vec<Vec<i32>>,
    ) {
        if target == 0 {
            result.push(path.clone());
            return;
        }
        for i in start..candidates.len() {
            if i > start && candidates[i] == candidates[i - 1] {
                continue;
            }
            if candidates[i] > target {
                continue;
            }
            path.push(candidates[i]);
            Self::backtrack(
                i + 1,
                target - candidates[i],
                path,
                candidates,
                result,
            );
            path.pop();
        }
    }
}

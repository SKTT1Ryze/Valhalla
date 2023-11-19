use super::{test_helper, Solution};

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Count and Say".into()
    }
    fn problem_id(&self) -> usize {
        39
    }
    fn location(&self) -> String {
        crate::location!()
    }
    fn test(&self) -> anyhow::Result<()> {
        test_helper(
            [
                (vec![2, 3, 5], 8),
                (vec![2], 1),
                (
                    vec![
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    ],
                    27,
                ),
            ],
            [vec![vec![3, 5], vec![2, 3, 3], vec![2, 2, 2, 2]], vec![]],
            |(candidates, target)| Self::combination_sum(candidates, target),
        )
    }
}

impl SolutionImpl {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut ans = Vec::new();

        Self::walk(&candidates, target, vec![], &mut ans);

        ans
    }

    fn walk(candidates: &[i32], target: i32, temp: Vec<i32>, ans: &mut Vec<Vec<i32>>) {
        if !candidates.is_empty() {
            let x = candidates[0];
            let mut i = 0;

            while x * i <= target {
                let mut temp = temp.clone();
                for _ in 0..i {
                    temp.push(x);
                }

                if x * i == target {
                    ans.push(temp);
                } else {
                    Self::walk(&candidates[1..], target - x * i, temp, ans);
                }

                i += 1;
            }
        }
    }
}

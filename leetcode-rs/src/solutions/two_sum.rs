use super::Solution;
use std::collections::HashMap;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Two Sum Solution using Map".into()
    }
    fn problem_id(&self) -> usize {
        1
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            (vec![2, 7, 11, 15], 9, [0, 1]),
            (vec![3, 2, 4], 6, [1, 2]),
            (vec![3, 3], 6, [0, 1]),
        ];

        for (input, target, expect) in testcases {
            let mut output = Self::two_sum(input.clone(), target);

            // sort output then compare
            output.sort();

            if expect[0] != output[0] || expect[1] != output[1] {
                anyhow::bail!(
                    "test failed for input={input:?} and target={target}. expect={expect:?}, \
                     output={output:?}"
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
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::<i32, usize>::new();
        let mut result = Vec::new();

        for (idx, value) in nums.into_iter().enumerate() {
            if let Some(x) = map.get(&(target - value)) {
                result.extend([idx as i32, *x as i32]);
            } else {
                map.insert(value, idx);
            }
        }

        result
    }
}

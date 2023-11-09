use std::collections::HashSet;

use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Solution for Remove Duplicates from Sorted Array".into()
    }
    fn problem_id(&self) -> usize {
        26
    }
    fn location(&self) -> String {
        crate::location!()
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            (vec![1, 1, 2], vec![1, 2]),
            (vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4], vec![0, 1, 2, 3, 4]),
        ];

        for (mut nums, expect) in testcases {
            let k = Self::remove_duplicates(&mut nums) as usize;

            if k != expect.len() || expect != nums[..k] {
                anyhow::bail!("test failed");
            }
        }

        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

impl SolutionImpl {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut set = HashSet::new();

        for &num in nums.iter() {
            set.insert(num);
        }

        let k = set.len();
        let mut v: Vec<_> = set.into_iter().collect();
        v.sort();
        *nums = v;

        k as i32
    }
}

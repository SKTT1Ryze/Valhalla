use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Remove Duplicates from Sorted Array II".into()
    }
    fn problem_id(&self) -> usize {
        80
    }
    fn location(&self) -> String {
        crate::location!()
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            (vec![1, 1, 1, 2, 2, 3], vec![1, 1, 2, 2, 3]),
            (vec![0, 0, 1, 1, 1, 1, 2, 3, 3], vec![0, 0, 1, 1, 2, 3, 3]),
        ];

        for (mut nums, expect) in testcases {
            let k = Self::remove_duplicates(&mut nums) as usize;

            if k != expect.len() || expect != nums[..k] {
                anyhow::bail!("test failed");
            }
        }

        Ok(())
    }
}

impl SolutionImpl {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        todo!()
    }
}

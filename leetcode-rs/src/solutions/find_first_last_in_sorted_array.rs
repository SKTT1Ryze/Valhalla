use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Find First and Last Position of Element in Sorted Array".into()
    }
    fn problem_id(&self) -> usize {
        34
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            (vec![5, 7, 7, 8, 8, 10], 8, vec![3, 4]),
            (vec![5, 7, 7, 8, 8, 10], 6, vec![-1, -1]),
            (vec![], 0, vec![-1, -1]),
        ];

        for (nums, target, expect) in testcases {
            let output = Self::search_range(nums.clone(), target);

            if output != expect {
                anyhow::bail!(
                    "test failed for nums={nums:?}, target={target} expect={expect:?}, \
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
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        todo!()
    }
}

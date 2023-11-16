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
            (vec![1], 0, vec![-1, -1]),
            (vec![1], 1, vec![0, 0]),
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
        if nums.is_empty() {
            return vec![-1, -1];
        }
        let mut ans = (-1, -1);

        Self::walk(&nums, target, 0, nums.len() - 1, &mut ans);

        vec![ans.0, ans.1]
    }

    fn walk(nums: &[i32], target: i32, m: usize, n: usize, ans: &mut (i32, i32)) {
        if m <= n {
            let k = (m + n) / 2;

            if target == nums[k] {
                ans.0 = if ans.0 == -1 {
                    k as i32
                } else {
                    ans.0.min(k as i32)
                };
                ans.1 = ans.1.max(k as i32);

                if k > 0 {
                    Self::walk(nums, target, m, k - 1, ans);
                }
                if k < nums.len() {
                    Self::walk(nums, target, k + 1, n, ans);
                }
            } else if target < nums[k] {
                if k > 0 {
                    Self::walk(nums, target, m, k - 1, ans);
                }
            } else {
                if k < nums.len() {
                    Self::walk(nums, target, k + 1, n, ans);
                }
            }
        }
    }
}

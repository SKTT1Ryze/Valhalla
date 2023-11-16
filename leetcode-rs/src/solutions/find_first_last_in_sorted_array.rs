use std::cmp::Ordering;

use super::{test_helper, Solution};

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
        test_helper(
            vec![
                (vec![5, 7, 7, 8, 8, 10], 8),
                (vec![5, 7, 7, 8, 8, 10], 6),
                (vec![], 0),
                (vec![1], 0),
                (vec![1], 1),
            ],
            vec![
                vec![3, 4],
                vec![-1, -1],
                vec![-1, -1],
                vec![-1, -1],
                vec![0, 0],
            ],
            |(nums, target)| Self::search_range(nums, target),
        )
    }
}

impl SolutionImpl {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        if nums.is_empty() {
            return vec![-1, -1];
        }
        let mut ans = (-1, -1);

        Self::walk(&nums, target, 0, nums.len() as i32 - 1, &mut ans);

        vec![ans.0, ans.1]
    }

    fn walk(nums: &[i32], target: i32, m: i32, n: i32, ans: &mut (i32, i32)) {
        if m <= n && m >= 0 && n >= 0 {
            let k = (m + n) / 2;

            match target.cmp(&nums[k as usize]) {
                Ordering::Equal => {
                    ans.0 = if ans.0 == -1 { k } else { ans.0.min(k) };
                    ans.1 = ans.1.max(k);

                    Self::walk(nums, target, m, k - 1, ans);
                    Self::walk(nums, target, k + 1, n, ans);
                }
                Ordering::Less => {
                    Self::walk(nums, target, m, k - 1, ans);
                }
                Ordering::Greater => {
                    Self::walk(nums, target, k + 1, n, ans);
                }
            }
        }
    }
}

use super::{test_helper, Solution};
use std::cmp::Ordering;

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
                (vec![1, 3, 5, 6], 0),
            ],
            [2, 1, 4, 0],
            |(nums, target)| Self::search_insert(nums, target),
        )
    }
}

impl SolutionImpl {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut ans = 0;
        let mut m = 0i32;
        let mut n = nums.len() as i32 - 1;

        while m <= n && m >= 0 && n >= 0 {
            let k = (m + n) / 2;

            match target.cmp(&nums[k as usize]) {
                Ordering::Equal => return k,
                Ordering::Greater => {
                    ans = n + 1;
                    m = k + 1;
                }
                Ordering::Less => {
                    ans = m;
                    n = k - 1;
                }
            }
        }

        ans
    }
}

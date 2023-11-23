use std::collections::HashSet;

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    47,
    "Permutations II",
    [vec![1, 1, 2], vec![1, 2, 3]],
    [
        vec![vec![1, 1, 2], vec![1, 2, 1], vec![2, 1, 1]],
        vec![
            vec![1, 2, 3],
            vec![1, 3, 2],
            vec![2, 1, 3],
            vec![2, 3, 1],
            vec![3, 1, 2],
            vec![3, 2, 1]
        ]
    ],
    |nums| {
        let mut output = Self::permute_unique(nums);
        output.sort();
        output
    }
);

impl SolutionImpl {
    pub fn permute_unique(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans = HashSet::new();

        Self::backtrack(&mut nums, 0, &mut ans);

        ans.into_iter().collect()
    }

    fn backtrack(nums: &mut Vec<i32>, start: usize, ans: &mut HashSet<Vec<i32>>) {
        ans.insert(nums.clone());
        let n = nums.len();
        if start < n - 1 {
            Self::backtrack(nums, start + 1, ans);
            for next in start + 1..n {
                nums.swap(start, next);
                Self::backtrack(nums, start + 1, ans);
                nums.swap(start, next);
            }
        }
    }
}

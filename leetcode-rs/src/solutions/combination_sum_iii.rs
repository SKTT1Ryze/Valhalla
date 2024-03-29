use super::{test_helper, Solution};
use std::collections::HashSet;

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    216,
    "Combination Sum III",
    [(3, 7), (3, 9), (4, 1)],
    [
        vec![vec![1, 2, 4]],
        vec![vec![1, 2, 6], vec![1, 3, 5], vec![2, 3, 4]],
        vec![]
    ],
    |(k, n)| Self::combination_sum3(k, n)
);

impl SolutionImpl {
    pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {
        let mut current = HashSet::new();
        let mut ans = HashSet::new();

        Self::backtracking(k, n, &mut current, &mut ans);

        ans.into_iter().collect()
    }

    fn backtracking(
        k: i32,
        target: i32,
        current: &mut HashSet<i32>,
        ans: &mut HashSet<Vec<i32>>,
    ) {
        if k == 0 {
            if target == 0 {
                let mut v: Vec<_> = current.clone().into_iter().collect();
                v.sort();
                ans.insert(v);
            }
        } else if Self::max_sum(k) >= target {
            for i in (current.len() as i32 + 1)..=9 {
                if !current.contains(&i) {
                    current.insert(i);
                    Self::backtracking(k - 1, target - i, current, ans);
                    current.remove(&i);
                }
            }
        }
    }

    fn max_sum(mut k: i32) -> i32 {
        let mut i = 9;
        let mut res = 0;

        while k > 0 {
            res += i;
            i -= 1;
            k -= 1;
        }

        res
    }
}

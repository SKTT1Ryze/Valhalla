use super::{test_helper, Solution};
use std::collections::HashSet;

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    78,
    "Subsets",
    [vec![1, 2, 3], vec![0],],
    [
        vec![
            vec![],
            vec![1],
            vec![1, 2],
            vec![1, 2, 3],
            vec![1, 3],
            vec![2],
            vec![2, 3],
            vec![3]
        ],
        vec![vec![], vec![0]]
    ],
    |nums| {
        let mut res = Self::subsets(nums);
        res.sort();
        res
    }
);

impl SolutionImpl {
    pub fn subsets(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans = HashSet::new();
        Self::backtracking(&mut ans, &mut nums);
        ans.insert(vec![]);
        ans.into_iter().collect()
    }

    fn backtracking(ans: &mut HashSet<Vec<i32>>, current: &mut Vec<i32>) {
        if !current.is_empty() {
            ans.insert(current.clone());
        }
        for i in 0..current.len() {
            let e = current.remove(i);
            Self::backtracking(ans, current);
            current.insert(i, e);
        }
    }
}

use std::collections::HashSet;

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    41,
    "First Missing Positive",
    [vec![1, 2, 0], vec![3, 4, -1, 1], vec![7, 8, 9, 11, 12]],
    [3, 2, 1],
    Self::first_missing_positive
);

impl SolutionImpl {
    pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let set: HashSet<_> =
            nums.into_iter().filter(|x| x.is_positive()).collect();

        for i in 0..n {
            let target = i as i32 + 1;
            if set.get(&target).is_none() {
                return target;
            }
        }

        n as i32 + 1
    }
}

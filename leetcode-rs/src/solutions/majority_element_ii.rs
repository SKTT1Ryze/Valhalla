use std::collections::VecDeque;

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    229,
    "Majority Element II",
    [vec![3, 2, 3], vec![1], vec![1, 2]],
    [vec![3], vec![1], vec![1, 2]],
    Self::majority_element
);

impl SolutionImpl {
    pub fn majority_element(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let threshold = n / 3;
        nums.sort();
        let mut nums = VecDeque::from(nums);

        let mut prev = nums.pop_back().unwrap();
        let mut num = 1;

        for _ in 0..n - 1 {
            let curr = nums.pop_back().unwrap();

            if curr == prev {
                num += 1;
            } else {
                if num > threshold {
                    nums.push_front(prev);
                }

                prev = curr;
                num = 1;
            }
        }

        if num > threshold {
            nums.push_front(prev);
        }

        nums.into()
    }
}

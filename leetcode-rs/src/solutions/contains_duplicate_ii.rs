use super::{test_helper, Solution};
use std::collections::HashMap;

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    219,
    "Contains Duplicate II",
    [
        (vec![1, 2, 3, 1], 3),
        (vec![1, 0, 1, 1], 1),
        (vec![1, 2, 3, 1, 2, 3], 2)
    ],
    [true, true, false],
    |(nums, k)| Self::contains_nearby_duplicate(nums, k)
);

impl SolutionImpl {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let k = k as usize;
        let mut map = HashMap::<i32, usize>::new();

        for (i, num) in nums.into_iter().enumerate() {
            if let Some(&prev) = map.get(&num) {
                if i - prev <= k {
                    return true;
                }
            }
            map.insert(num, i);
        }

        false
    }
}

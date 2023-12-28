use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    81,
    "Search in Rotated Sorted Array II",
    [
        (vec![2, 5, 6, 0, 0, 1, 2], 0),
        (vec![2, 5, 6, 0, 0, 1, 2], 3),
        (vec![1, 0, 1, 1, 1], 0)
    ],
    [true, false, true],
    |(nums, target)| Self::search(nums, target)
);

impl SolutionImpl {
    pub fn search(nums: Vec<i32>, target: i32) -> bool {
        let mut start = 0i32;
        let mut end = nums.len() as i32 - 1;

        while start <= end {
            let mid = (start + end) as usize / 2;

            if nums[mid] == target {
                return true;
            }

            while start < mid as i32 && nums[start as usize] == nums[mid] {
                start += 1;
            }

            if nums[start as usize] <= nums[mid] {
                // start..mid is sorted
                if nums[start as usize] <= target && target < nums[mid] {
                    end = mid as i32 - 1;
                } else {
                    start = mid as i32 + 1;
                }
            } else {
                // mid..end is sorted
                if nums[mid] < target && target <= nums[end as usize] {
                    start = mid as i32 + 1;
                } else {
                    end = mid as i32 - 1;
                }
            }
        }

        false
    }
}

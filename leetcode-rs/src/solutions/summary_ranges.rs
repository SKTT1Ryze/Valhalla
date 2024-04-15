use std::ops::Range;

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    228,
    "Summary Ranges",
    [vec![0, 1, 2, 4, 5, 7], vec![0, 2, 3, 4, 6, 8, 9],],
    [
        vec!["0->2".into(), "4->5".into(), "7".into()],
        vec!["0".into(), "2->4".into(), "6".into(), "8->9".into()]
    ],
    Self::summary_ranges
);

impl SolutionImpl {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        if nums.is_empty() {
            return vec![];
        }
        let mut ranges: Vec<Range<i32>> = Vec::new();
        let mut start = nums[0];
        let mut end = nums[0] + 1;

        for num in nums.into_iter().skip(1) {
            if num == end {
                end += 1;
            } else {
                ranges.push(start..end);
                start = num;
                end = num + 1;
            }
        }

        ranges.push(start..end);

        ranges
            .into_iter()
            .map(|range| {
                if range.len() == 1 || range.start == i32::MAX {
                    format!("{}", range.start)
                } else {
                    format!("{}->{}", range.start, range.end - 1)
                }
            })
            .collect()
    }
}

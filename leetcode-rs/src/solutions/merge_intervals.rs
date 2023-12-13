use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    56,
    "Merge Intervals",
    [
        vec![vec![1, 3], vec![2, 6], vec![8, 10], vec![15, 18]],
        vec![vec![1, 4], vec![4, 5]]
    ],
    [
        vec![vec![1, 6], vec![8, 10], vec![15, 18]],
        vec![vec![1, 5]]
    ],
    Self::merge
);

impl SolutionImpl {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        intervals.sort();
        let mut res = Vec::new();
        let n = intervals.len();
        let mut start = intervals[0][0];
        let mut end = intervals[0][1];

        for (i, interval) in intervals.into_iter().enumerate() {
            if end < interval[0] {
                res.push(vec![start, end]);
                start = interval[0];
                end = interval[1];
            } else {
                start = start.min(interval[0]);
                end = end.max(interval[1]);
            }
            if i == n - 1 {
                res.push(vec![start, end]);
            }
        }

        res
    }
}

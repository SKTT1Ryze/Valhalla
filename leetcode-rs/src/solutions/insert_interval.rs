use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    57,
    "Insert Interval",
    [
        (vec![vec![1, 3], vec![6, 9]], vec![2, 5]),
        (
            vec![
                vec![1, 2],
                vec![3, 5],
                vec![6, 7],
                vec![8, 10],
                vec![12, 16]
            ],
            vec![4, 8]
        )
    ],
    [
        (vec![vec![1, 5], vec![6, 9]]),
        (vec![vec![1, 2], vec![3, 10], vec![12, 16]])
    ],
    |(intervals, new_interval)| Self::insert(intervals, new_interval)
);

impl SolutionImpl {
    pub fn insert(
        mut intervals: Vec<Vec<i32>>,
        new_interval: Vec<i32>,
    ) -> Vec<Vec<i32>> {
        intervals.push(new_interval);
        Self::merge(intervals)
    }

    fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
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

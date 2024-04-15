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
        todo!()
    }
}

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    53,
    "Maximum Subarray",
    [
        vec![-2, 1, -3, 4, -1, 2, 1, -5, 4],
        vec![1],
        vec![5, 4, -1, 7, 8]
    ],
    [6, 1, 23],
    Self::max_sub_array
);

impl SolutionImpl {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        todo!()
    }
}

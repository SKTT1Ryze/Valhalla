use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    179,
    "Largest Numver",
    [vec![10, 2], vec![3, 30, 34, 5, 9]],
    ["210".into(), "9534330".into()],
    Self::largest_number
);

impl SolutionImpl {
    pub fn largest_number(nums: Vec<i32>) -> String {
        todo!()
    }
}

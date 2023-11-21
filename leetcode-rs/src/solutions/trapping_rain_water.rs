use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    42,
    "Trapping Rain Water",
    [
        vec![0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1],
        vec![4, 2, 0, 3, 2, 5]
    ],
    [6, 9],
    Self::trap
);

impl SolutionImpl {
    pub fn trap(height: Vec<i32>) -> i32 {
        todo!()
    }
}

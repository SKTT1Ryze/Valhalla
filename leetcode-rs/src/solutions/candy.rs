use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    135,
    "Candy",
    [vec![1, 0, 2], vec![1, 2, 2]],
    [5, 4],
    Self::candy
);

impl SolutionImpl {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        todo!()
    }
}

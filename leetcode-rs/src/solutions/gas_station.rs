use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    134,
    "Gas Station",
    [
        (vec![1, 2, 3, 4, 5], vec![3, 4, 5, 1, 2]),
        (vec![2, 3, 4], vec![3, 4, 3]),
    ],
    [3, -1],
    |(gas, cost)| Self::can_complete_circuit(gas, cost)
);

impl SolutionImpl {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        todo!()
    }
}

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    70,
    "Climbing Stairs",
    [2, 3],
    [2, 3],
    Self::climb_stairs
);

impl SolutionImpl {
    pub fn climb_stairs(n: i32) -> i32 {
        todo!()
    }
}

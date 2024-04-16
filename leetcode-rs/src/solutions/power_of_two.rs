use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    231,
    "Power of Two",
    [1, 16, 3],
    [true, true, false],
    Self::is_power_of_two
);

impl SolutionImpl {
    pub fn is_power_of_two(n: i32) -> bool {
        if n == 1 {
            true
        } else if n == 0 {
            false
        } else {
            n % 2 == 0 && Self::is_power_of_two(n / 2)
        }
    }
}

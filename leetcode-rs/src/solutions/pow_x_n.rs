use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    50,
    "Pow(x, n)",
    [(2.00000, 10), (2.10000, 3), (2.00000, -2)],
    [1024.00000, 9.26100, 0.25000],
    |(x, n)| Self::my_pow(x, n)
);

impl SolutionImpl {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        todo!()
    }
}

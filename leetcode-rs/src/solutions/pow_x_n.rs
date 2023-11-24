use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    50,
    "Pow(x, n)",
    [
        (2.00000, 10),
        (2.10000, 3),
        (2.00000, -2),
        (2.00000, -2147483648)
    ],
    [1024.00000, 9.26100, 0.25000, 0.00000],
    |(x, n)| (Self::my_pow(x, n) * 100000_f64).round() / 100000_f64
);

impl SolutionImpl {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        let mut result = 1.0;
        let mut base = x;
        let mut exponent = n as i64;

        if exponent < 0 {
            base = 1.0 / x;
            exponent = -exponent;
        }

        while exponent > 0 {
            if exponent % 2 == 1 {
                result *= base;
            }
            base *= base;
            exponent /= 2;
        }

        result
    }
}

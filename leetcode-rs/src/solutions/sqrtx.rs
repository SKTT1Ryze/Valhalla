use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    69,
    "Sqrt(x)",
    [4, 8, 2147395599],
    [2, 2, 46339],
    Self::my_sqrt
);

impl SolutionImpl {
    pub fn my_sqrt(x: i32) -> i32 {
        let x = x as i64;
        let mut res = x / 2;

        loop {
            if res * res <= x && (res + 1) * (res + 1) > x {
                break;
            } else if (res + 1) * (res + 1) <= x {
                res += 1;
            } else {
                res /= 2;
            }
        }

        res as i32
    }
}

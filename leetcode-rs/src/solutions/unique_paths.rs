use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    62,
    "Unique Paths",
    [(3, 7), (3, 2)],
    [28, 3],
    |(m, n)| Self::unique_paths(m, n)
);

impl SolutionImpl {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        todo!()
    }
}

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    60,
    "Permutation Sequence",
    [(3, 3), (4, 9), (3, 1)],
    ["213".into(), "2314".into(), "123".into()],
    |(n, k)| Self::get_permutation(n, k)
);

impl SolutionImpl {
    pub fn get_permutation(n: i32, k: i32) -> String {
        todo!()
    }
}

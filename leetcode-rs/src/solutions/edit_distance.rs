use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    72,
    "Edit Distance",
    [("horse", "ros"), ("intention", "execution")],
    [3, 5],
    |(word1, word2)| Self::min_distance(word1.into(), word2.into())
);

impl SolutionImpl {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        todo!()
    }
}

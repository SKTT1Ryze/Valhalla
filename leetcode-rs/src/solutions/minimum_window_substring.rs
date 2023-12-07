use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    76,
    "Minimum Window Substring",
    [
        ("ADOBECODEBANC".into(), "ABC".into()),
        ("a".into(), "a".into()),
        ("a".into(), "aa".into())
    ],
    ["BANC".into(), "a".into(), "".into()],
    |(s, t)| Self::min_window(s, t)
);

impl SolutionImpl {
    pub fn min_window(s: String, t: String) -> String {
        todo!()
    }
}

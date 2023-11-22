use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    44,
    "Wildcard Matching",
    [("aa", "a"), ("aa", "*"), ("cb", "?a")],
    [false, true, false],
    |(s, p)| Self::is_match(s.to_string(), p.to_string())
);

impl SolutionImpl {
    pub fn is_match(s: String, p: String) -> bool {
        todo!()
    }
}

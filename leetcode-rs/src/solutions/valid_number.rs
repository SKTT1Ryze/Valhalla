use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    65,
    "Valid Number",
    ["0", "e", "."],
    [true, false, false],
    |s| Self::is_number(s.into())
);

impl SolutionImpl {
    pub fn is_number(s: String) -> bool {
        todo!()
    }
}

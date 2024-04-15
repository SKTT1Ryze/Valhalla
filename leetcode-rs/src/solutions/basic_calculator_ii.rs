use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    227,
    "Basic Calculator II",
    ["3+2*2".into(), " 3/2 ".into(), " 3+5 / 2 ".into()],
    [7, 1, 5],
    Self::calculate
);

impl SolutionImpl {
    pub fn calculate(s: String) -> i32 {
        todo!()
    }
}

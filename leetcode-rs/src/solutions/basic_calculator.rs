use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    224,
    "Basic Calculator",
    [
        "1 + 1".into(),
        " 2-1 + 2 ".into(),
        "(1+(4+5+2)-3)+(6+8)".into()
    ],
    [2, 3, 23],
    Self::calculate
);

impl SolutionImpl {
    pub fn calculate(s: String) -> i32 {
        todo!()
    }
}

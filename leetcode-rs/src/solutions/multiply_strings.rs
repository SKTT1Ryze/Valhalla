use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    43,
    "Multiply Strings",
    [("2", "3"), ("123", "456")],
    ["6".into(), "56088".into()],
    |(num1, num2)| Self::multiply(num1.into(), num2.into())
);

impl SolutionImpl {
    pub fn multiply(num1: String, num2: String) -> String {
        todo!()
    }
}

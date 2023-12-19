use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    67,
    "Add Binary",
    [("11", "1"), ("1010", "1011")],
    ["100".into(), "10101".into()],
    |(a, b)| Self::add_binary(a.into(), b.into())
);

impl SolutionImpl {
    pub fn add_binary(a: String, b: String) -> String {
        todo!()
    }
}

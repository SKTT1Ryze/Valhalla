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
    pub fn add_binary(mut a: String, mut b: String) -> String {
        let mut res = Vec::<char>::new();
        let mut upgrade = 0;

        while !(a.is_empty() || b.is_empty()) {
            let a = a.pop().unwrap() as u8 - 48;
            let b = b.pop().unwrap() as u8 - 48;
            let sum = a + b + upgrade;
            upgrade = sum / 2;
            res.push((sum % 2 + 48) as char);
        }

        while let Some(a) = a.pop() {
            let a = a as u8 - 48;
            let sum = a + upgrade;
            upgrade = sum / 2;
            res.push((sum % 2 + 48) as char);
        }

        while let Some(b) = b.pop() {
            let b = b as u8 - 48;
            let sum = b + upgrade;
            upgrade = sum / 2;
            res.push((sum % 2 + 48) as char);
        }

        if upgrade > 0 {
            res.push('1');
        }

        res.into_iter().rev().collect()
    }
}

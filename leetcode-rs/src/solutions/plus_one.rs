use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    66,
    "Plus One",
    [vec![1, 2, 3], vec![4, 3, 2, 1], vec![9]],
    [vec![1, 2, 4], vec![4, 3, 2, 2], vec![1, 0]],
    Self::plus_one
);

impl SolutionImpl {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut res = vec![];
        let mut upgrade = 1;

        while let Some(digit) = digits.pop() {
            let sum = digit + upgrade;
            upgrade = sum / 10;
            res.push(sum % 10);
        }

        if upgrade > 0 {
            res.push(upgrade);
        }

        res.into_iter().rev().collect()
    }
}

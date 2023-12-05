use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    179,
    "Largest Numver",
    [vec![10, 2], vec![3, 30, 34, 5, 9]],
    ["210".into(), "9534330".into()],
    Self::largest_number
);

impl SolutionImpl {
    pub fn largest_number(nums: Vec<i32>) -> String {
        let mut num_strs: Vec<_> =
            nums.into_iter().map(|num| num.to_string()).collect();

        num_strs.sort_by(|a, b| (b.clone() + a).cmp(&(a.clone() + b)));

        let result: String = num_strs.join("").trim_start_matches('0').into();

        if result.is_empty() {
            "0".to_string()
        } else {
            result
        }
    }
}

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    121,
    "Best Time to Buy and Sell Stock",
    [vec![7, 1, 5, 3, 6, 4], vec![7, 6, 4, 3, 1],],
    [5, 0],
    Self::max_profit
);

impl SolutionImpl {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        todo!()
    }
}

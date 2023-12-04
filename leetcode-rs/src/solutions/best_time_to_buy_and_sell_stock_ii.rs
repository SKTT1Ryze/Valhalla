use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    122,
    "Best Time to Buy and Sell Stock II",
    [
        vec![7, 1, 5, 3, 6, 4],
        vec![1, 2, 3, 4, 5],
        vec![7, 6, 4, 3, 1]
    ],
    [7, 4, 0],
    Self::max_profit
);

impl SolutionImpl {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut profit = 0;

        for i in 0..prices.len() - 1 {
            if prices[i] < prices[i + 1] {
                profit += prices[i + 1] - prices[i];
            }
        }

        profit
    }
}

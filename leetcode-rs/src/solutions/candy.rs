use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    135,
    "Candy",
    [vec![1, 0, 2], vec![1, 2, 2]],
    [5, 4],
    Self::candy
);

impl SolutionImpl {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let n = ratings.len();
        let mut candis = vec![1; n];

        for i in 1..n {
            if ratings[i] > ratings[i - 1] {
                candis[i] = candis[i - 1] + 1;
            }
        }

        for i in (0..n - 1).rev() {
            if ratings[i] > ratings[i + 1] {
                candis[i] = candis[i].max(candis[i + 1] + 1);
            }
        }

        candis.into_iter().sum()
    }
}

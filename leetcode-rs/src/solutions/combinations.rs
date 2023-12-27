use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    77,
    "Combinations",
    [(4, 2), (1, 1)],
    [
        vec![
            vec![1, 2],
            vec![1, 3],
            vec![1, 4],
            vec![2, 3],
            vec![2, 4],
            vec![3, 4]
        ],
        vec![vec![1]]
    ],
    |(n, k)| Self::combine(n, k)
);

impl SolutionImpl {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        let mut ans = vec![];
        let mut current = vec![];
        Self::backtracking(&mut ans, &mut current, n, k, 0);
        ans
    }

    fn backtracking(
        ans: &mut Vec<Vec<i32>>,
        current: &mut Vec<i32>,
        n: i32,
        k: i32,
        i: i32,
    ) {
        if current.len() == k as usize {
            ans.push(current.clone());
        } else {
            for j in i + 1..=n {
                current.push(j);
                Self::backtracking(ans, current, n, k, j);
                current.pop();
            }
        }
    }
}

use super::{mut_test_helper, Solution};
use std::collections::HashSet;

pub struct SolutionImpl;

crate::derive_inplace_solution!(
    SolutionImpl,
    73,
    "Set Matrix Zeroes",
    [
        vec![vec![1, 1, 1], vec![1, 0, 1], vec![1, 1, 1]],
        vec![vec![0, 1, 2, 0], vec![3, 4, 5, 2], vec![1, 3, 1, 5]]
    ],
    [
        vec![vec![1, 0, 1], vec![0, 0, 0], vec![1, 0, 1]],
        vec![vec![0, 0, 0, 0], vec![0, 4, 5, 0], vec![0, 3, 1, 0]]
    ],
    Self::set_zeroes
);

impl SolutionImpl {
    #[allow(clippy::ptr_arg)]
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let m = matrix.len();
        let n = matrix[0].len();

        let mut zero_rows = HashSet::new();
        let mut zero_cols = HashSet::new();

        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] == 0 {
                    zero_rows.insert(i);
                    zero_cols.insert(j);
                }
            }
        }

        for &row in &zero_rows {
            for j in 0..n {
                matrix[row][j] = 0;
            }
        }

        for &col in &zero_cols {
            for i in 0..m {
                matrix[i][col] = 0;
            }
        }
    }
}

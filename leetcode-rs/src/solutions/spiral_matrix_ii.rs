use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    59,
    "Spiral Matrix II",
    [3, 1],
    [
        vec![vec![1, 2, 3], vec![8, 9, 4], vec![7, 6, 5]],
        vec![vec![1]]
    ],
    Self::generate_matrix
);

impl SolutionImpl {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let mut matrix = vec![vec![0; n as usize]; n as usize];

        let (mut row_start, mut row_end) = (0, n - 1);
        let (mut col_start, mut col_end) = (0, n - 1);
        let mut num = 1;

        #[allow(clippy::needless_range_loop)]
        while row_start <= row_end && col_start <= col_end {
            for j in col_start..=col_end {
                matrix[row_start as usize][j as usize] = num;
                num += 1;
            }
            row_start += 1;

            for i in row_start..=row_end {
                matrix[i as usize][col_end as usize] = num;
                num += 1;
            }
            col_end -= 1;

            if row_start <= row_end {
                for j in (col_start..=col_end).rev() {
                    matrix[row_end as usize][j as usize] = num;
                    num += 1;
                }
                row_end -= 1;
            }

            // Traverse up
            if col_start <= col_end {
                for i in (row_start..=row_end).rev() {
                    matrix[i as usize][col_start as usize] = num;
                    num += 1;
                }
                col_start += 1;
            }
        }

        matrix
    }
}

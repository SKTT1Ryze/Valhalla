use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    54,
    "Spiral Matrix",
    [
        vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]],
        vec![vec![1, 2, 3, 4], vec![5, 6, 7, 8], vec![9, 10, 11, 12]]
    ],
    [
        vec![1, 2, 3, 6, 9, 8, 7, 4, 5],
        vec![1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
    ],
    Self::spiral_order
);

impl SolutionImpl {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        if matrix.is_empty() || matrix[0].is_empty() {
            return Vec::new();
        }

        let mut result = Vec::new();
        let (mut row_start, mut row_end) = (0, matrix.len() as i32 - 1);
        let (mut col_start, mut col_end) = (0, matrix[0].len() as i32 - 1);

        #[allow(clippy::needless_range_loop)]
        while row_start <= row_end && col_start <= col_end {
            // Traverse right
            for j in col_start..=col_end {
                result.push(matrix[row_start as usize][j as usize]);
            }
            row_start += 1;

            // Traverse down
            for i in row_start..=row_end {
                result.push(matrix[i as usize][col_end as usize]);
            }
            col_end -= 1;

            // Traverse left
            if row_start <= row_end {
                for j in (col_start..=col_end).rev() {
                    result.push(matrix[row_end as usize][j as usize]);
                }
                row_end -= 1;
            }

            // Traverse up
            if col_start <= col_end {
                for i in (row_start..=row_end).rev() {
                    result.push(matrix[i as usize][col_start as usize]);
                }
                col_start += 1;
            }
        }

        result
    }
}

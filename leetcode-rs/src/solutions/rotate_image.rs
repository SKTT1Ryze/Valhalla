use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    48,
    "Rotate Image",
    [
        vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]],
        vec![
            vec![5, 1, 9, 11],
            vec![2, 4, 8, 10],
            vec![13, 3, 6, 7],
            vec![15, 14, 12, 16]
        ]
    ],
    [
        vec![vec![7, 4, 1], vec![8, 5, 2], vec![9, 6, 3]],
        vec![
            vec![15, 13, 2, 5],
            vec![14, 3, 4, 1],
            vec![12, 6, 8, 9],
            vec![16, 7, 10, 11]
        ]
    ],
    |mut matrix| {
        Self::rotate(&mut matrix);
        matrix
    }
);

impl SolutionImpl {
    #[allow(clippy::ptr_arg)]
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();

        let mut step = n as i32;

        while step > 1 {
            for i in 0..step.wrapping_sub(1) as usize {
                // swap matrix[step/2 + i][step/2], matrix[n -
                // step/2][step/2 + i], matrix[n -
                // step/2 - i][n - step/2],
                // matrix[step/2][n - step/2 - i]

                let step = n - step as usize;
                let n = n - 1;

                // let temp = matrix[step / 2 + i][step / 2];
                // matrix[step / 2 + i][step / 2] = matrix[step / 2][n
                // - step / 2 - i]; matrix[step / 2][n
                // - step / 2 - i] = matrix[n - step / 2 - i][n - step
                // / 2]; matrix[n - step / 2 - i][n -
                // step / 2] = matrix[n - step / 2][step / 2 + i];
                // matrix[n - step / 2][step / 2 + i] = temp;

                let temp = matrix[n - step / 2][step / 2 + i];
                matrix[n - step / 2][step / 2 + i] = matrix[n - step / 2 - i][n - step / 2];
                matrix[n - step / 2 - i][n - step / 2] = matrix[step / 2][n - step / 2 - i];
                matrix[step / 2][n - step / 2 - i] = matrix[step / 2 + i][step / 2];
                matrix[step / 2 + i][step / 2] = temp;
            }

            step = step.wrapping_sub(2);
        }
    }
}

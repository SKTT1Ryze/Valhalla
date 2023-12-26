use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    74,
    "Search a 2D Matrix",
    [
        (
            vec![vec![1, 3, 5, 7], vec![10, 11, 16, 20], vec![23, 30, 34, 60]],
            3
        ),
        (
            vec![vec![1, 3, 5, 7], vec![10, 11, 16, 20], vec![23, 30, 34, 60]],
            13
        ),
        (vec![vec![1]], 1),
        (vec![vec![1]], 0),
        (vec![vec![1]], 2),
        (
            vec![vec![1, 3, 5, 7], vec![10, 11, 16, 20], vec![23, 30, 34, 50]],
            11
        )
    ],
    [true, false, true, false, false, true],
    |(matrix, target)| Self::search_matrix(matrix, target)
);

impl SolutionImpl {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut start = 0i32;
        let mut end = m as i32 - 1;
        let mut row: Option<usize> = None;

        while start <= end {
            if matrix[start as usize][0] <= target
                && matrix[start as usize][n - 1] >= target
            {
                row = Some(start as usize);
                break;
            } else if matrix[end as usize][0] <= target
                && matrix[end as usize][n - 1] >= target
            {
                row = Some(end as usize);
                break;
            } else {
                let mid = (start + end) / 2;
                if matrix[mid as usize][0] <= target
                    && matrix[mid as usize][n - 1] >= target
                {
                    row = Some(mid as usize);
                    break;
                } else if matrix[mid as usize][n - 1] < target {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        if let Some(row) = row {
            let mut start = 0i32;
            let mut end = n as i32 - 1;

            while start <= end {
                if matrix[row][start as usize] == target
                    || matrix[row][end as usize] == target
                {
                    return true;
                } else {
                    let mid = (start + end) / 2;
                    if matrix[row][mid as usize] == target {
                        return true;
                    } else if matrix[row][mid as usize] <= target {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }

            false
        } else {
            false
        }
    }
}

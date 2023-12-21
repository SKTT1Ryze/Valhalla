use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    52,
    "N-Queens II",
    [4, 1],
    [2, 1],
    Self::total_n_queens
);

impl SolutionImpl {
    pub fn total_n_queens(n: i32) -> i32 {
        let n = n as usize;
        let mut ans = 0;
        let mut board = vec![vec!['.'; n]; n];
        Self::backtracking(&mut ans, &mut board, 0, n);
        ans
    }

    fn backtracking(
        ans: &mut i32,
        board: &mut Vec<Vec<char>>,
        row: usize,
        n: usize,
    ) {
        if row == n {
            *ans += 1;
        } else if row < n - 1 && !board[row + 1].iter().any(|&cell| cell == '.')
        {
            // there is an available position in the next row
        } else {
            for col in 0..n {
                if Self::is_safe(board, row, col, n) {
                    board[row][col] = 'Q';
                    Self::backtracking(ans, board, row + 1, n);
                    board[row][col] = '.';
                }
            }
        }
    }

    fn is_safe(board: &[Vec<char>], row: usize, col: usize, n: usize) -> bool {
        // Check if there is a queen in the same row
        if board[row].iter().any(|&cell| cell == 'Q') {
            return false;
        }

        // Check if there is a queen in the same column
        #[allow(clippy::needless_range_loop)]
        for i in 0..row {
            if board[i][col] == 'Q' {
                return false;
            }
        }

        // Check if there is a queen in the left diagonal
        let mut i = row as i32 - 1;
        let mut j = col as i32 - 1;
        while i >= 0 && j >= 0 {
            if board[i as usize][j as usize] == 'Q' {
                return false;
            }
            i -= 1;
            j -= 1;
        }

        // Check if there is a queen in the right diagonal
        let mut i = row as i32 - 1;
        let mut j = col as i32 + 1;
        while i >= 0 && j < n as i32 {
            if board[i as usize][j as usize] == 'Q' {
                return false;
            }
            i -= 1;
            j += 1;
        }

        true
    }
}

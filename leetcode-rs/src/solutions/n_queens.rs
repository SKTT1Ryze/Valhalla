use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    51,
    "N-Queens",
    [4, 1],
    [
        vec![
            vec![".Q..", "...Q", "Q...", "..Q."],
            vec!["..Q.", "Q...", "...Q", ".Q.."]
        ],
        vec![vec!["Q"]]
    ]
    .into_iter()
    .map(|v| v
        .into_iter()
        .map(|v| v.into_iter().map(std::convert::Into::into).collect())
        .collect())
    .collect::<Vec<_>>(),
    Self::solve_n_queens
);

impl SolutionImpl {
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let n = n as usize;
        let mut ans = Vec::new();
        let mut board = vec![vec!['.'; n]; n];
        Self::backtracking(&mut ans, &mut board, 0, n);
        ans
    }

    fn backtracking(
        result: &mut Vec<Vec<String>>,
        board: &mut Vec<Vec<char>>,
        row: usize,
        n: usize,
    ) {
        if row == n {
            // Convert the current board state to a vector of strings and add to
            // the result
            result.push(board.iter().map(|r| r.iter().collect()).collect());
            return;
        }

        // Check if there is an available position in the next row
        if row < n - 1 && !board[row + 1].iter().any(|&cell| cell == '.') {
            return;
        }

        for col in 0..n {
            if Self::is_safe(board, row, col, n) {
                board[row][col] = 'Q';
                Self::backtracking(result, board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }

    fn is_safe(board: &[Vec<char>], row: usize, col: usize, n: usize) -> bool {
        // Check if there is a queen in the same row
        if board[row].iter().any(|&cell| cell == 'Q') {
            return false;
        }

        // Check if there is a queen in the same column
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

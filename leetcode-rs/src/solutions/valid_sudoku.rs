use std::collections::HashSet;

use super::{test_helper, Solution};

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Valid Sudoku".into()
    }
    fn problem_id(&self) -> usize {
        36
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        test_helper(
            [[
                ["5", "3", ".", ".", "7", ".", ".", ".", "."],
                ["6", ".", ".", "1", "9", "5", ".", ".", "."],
                [".", "9", "8", ".", ".", ".", ".", "6", "."],
                ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
                ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
                ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                [".", "6", ".", ".", ".", ".", "2", "8", "."],
                [".", ".", ".", "4", "1", "9", ".", ".", "5"],
                [".", ".", ".", ".", "8", ".", ".", "7", "9"],
            ]],
            [true],
            |board| {
                let board: Vec<Vec<_>> = board
                    .into_iter()
                    .map(|v| v.into_iter().map(|s| s.chars().nth(0).unwrap()).collect())
                    .collect();

                Self::is_valid_sudoku(board)
            },
        )
    }
}

impl SolutionImpl {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        for i in 0..9 {
            let mut uniq_row = HashSet::new();
            let mut uniq_col = HashSet::new();
            for j in 0..9 {
                if board[i][j] != '.' && !uniq_row.insert(&board[i][j]) {
                    return false;
                }

                if board[j][i] != '.' && !uniq_col.insert(&board[j][i]) {
                    return false;
                }
            }
        }

        for i in 0..3 {
            for j in 0..3 {
                let mut uniq = HashSet::new();
                if !&board[i * 3..(i + 1) * 3]
                    .iter()
                    .flat_map(|v| v[j * 3..(j + 1) * 3].iter())
                    .all(|&e| e == '.' || uniq.insert(e))
                {
                    return false;
                }
            }
        }

        true
    }
}

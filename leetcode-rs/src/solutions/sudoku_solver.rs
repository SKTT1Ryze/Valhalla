use super::{mut_test_helper, Solution};

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Sudoku Solver".into()
    }
    fn problem_id(&self) -> usize {
        37
    }
    fn location(&self) -> String {
        crate::location!()
    }
    fn test(&self) -> anyhow::Result<()> {
        let transform = |board: [[char; 9]; 9]| {
            board.into_iter().map(|v| v.into_iter().collect()).collect()
        };

        mut_test_helper(
            [transform([
                ['5', '3', '.', '.', '7', '.', '.', '.', '.'],
                ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
                ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
                ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
                ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
                ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
                ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
                ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
                ['.', '.', '.', '.', '8', '.', '.', '7', '9'],
            ])],
            [transform([
                ['5', '3', '4', '6', '7', '8', '9', '1', '2'],
                ['6', '7', '2', '1', '9', '5', '3', '4', '8'],
                ['1', '9', '8', '3', '4', '2', '5', '6', '7'],
                ['8', '5', '9', '7', '6', '1', '4', '2', '3'],
                ['4', '2', '6', '8', '5', '3', '7', '9', '1'],
                ['7', '1', '3', '9', '2', '4', '8', '5', '6'],
                ['9', '6', '1', '5', '3', '7', '2', '8', '4'],
                ['2', '8', '7', '4', '1', '9', '6', '3', '5'],
                ['3', '4', '5', '2', '8', '6', '1', '7', '9'],
            ])],
            Self::solve_sudoku,
        )
    }
}

impl SolutionImpl {
    #[allow(clippy::ptr_arg)]
    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        Self::walk(board, 0, 0);
    }

    fn walk(board: &mut Vec<Vec<char>>, i: usize, j: usize) -> bool {
        if i == 9 {
            return true;
        } else if j == 9 {
            return Self::walk(board, i + 1, 0);
        }

        let block = board[i][j];

        if block == '.' {
            for k in '1'..='9' {
                if !board[i].contains(&k)
                    && !board
                        .iter()
                        .map(|v| v[j])
                        .collect::<Vec<_>>()
                        .contains(&k)
                    && !board[(i / 3) * 3..(i / 3 + 1) * 3]
                        .iter()
                        .flat_map(|v| v[(j / 3) * 3..(j / 3 + 1) * 3].iter())
                        .copied()
                        .collect::<Vec<_>>()
                        .contains(&k)
                {
                    board[i][j] = k;
                    if Self::walk(board, i, j + 1) {
                        return true;
                    }
                }
            }
            // recover
            board[i][j] = '.';
            false
        } else {
            Self::walk(board, i, j + 1)
        }
    }
}

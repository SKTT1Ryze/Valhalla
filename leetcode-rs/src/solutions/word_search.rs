use super::{test_helper, Solution};
use std::collections::HashSet;

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    79,
    "Word Search",
    [
        (
            vec![
                vec!['A', 'B', 'C', 'E'],
                vec!['S', 'F', 'C', 'S'],
                vec!['A', 'D', 'E', 'E']
            ],
            "ABCCED".to_string()
        ),
        (
            vec![
                vec!['A', 'B', 'C', 'E'],
                vec!['S', 'F', 'C', 'S'],
                vec!['A', 'D', 'E', 'E']
            ],
            "SEE".to_owned()
        ),
        (vec![vec!['a']], "a".to_owned()),
    ],
    [true, true, true],
    |(board, word)| Self::exist(board, word)
);

impl SolutionImpl {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        for i in 0..board.len() {
            for j in 0..board[0].len() {
                if board[i][j] == word.chars().nth(0).unwrap() {
                    let mut set = HashSet::from([(i as i32, j as i32)]);
                    if Self::backtracking(
                        &board,
                        &mut set,
                        i as i32,
                        j as i32,
                        &word[1..],
                    ) {
                        return true;
                    }
                }
            }
        }
        false
    }

    fn backtracking(
        board: &[Vec<char>],
        mark: &mut HashSet<(i32, i32)>,
        i: i32,
        j: i32,
        word: &str,
    ) -> bool {
        if word.is_empty() {
            true
        } else {
            for (m, n) in [(1i32, 0i32), (-1, 0), (0, 1), (0, -1)] {
                let next_i = i + m;
                let next_j = j + n;

                if !mark.contains(&(next_i, next_j))
                    && next_i >= 0
                    && (next_i as usize) < board.len()
                    && next_j >= 0
                    && (next_j as usize) < board[0].len()
                    && board[next_i as usize][next_j as usize]
                        == word.chars().nth(0).unwrap()
                {
                    mark.insert((next_i, next_j));
                    if Self::backtracking(
                        board,
                        mark,
                        next_i,
                        next_j,
                        &word[1..],
                    ) {
                        return true;
                    }
                    mark.remove(&(next_i, next_j));
                }
            }

            false
        }
    }
}

use super::Solution;

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Solution for Zigzag Conversion".into()
    }
    fn problem_id(&self) -> usize {
        6
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            ("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),
            ("PAYPALISHIRING", 4, "PINALSIGYAHRPI"),
            ("ABCD", 2, "ACBD"),
            ("A", 1, "A"),
        ];

        for (s, num_rows, expect) in testcases {
            let output = Self::convert(s.into(), num_rows);

            if output != expect {
                anyhow::bail!(
                    "test failed for s={s}, num_rows={num_rows}, expect={expect}, output={output}"
                );
            }
        }

        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

impl SolutionImpl {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows <= 1 {
            return s;
        }
        if num_rows == 2 {
            return [
                s.chars()
                    .into_iter()
                    .enumerate()
                    .filter_map(|(i, ch)| if i % 2 == 0 { Some(ch) } else { None })
                    .collect::<Vec<_>>(),
                s.chars()
                    .into_iter()
                    .enumerate()
                    .filter_map(|(i, ch)| if i % 2 != 0 { Some(ch) } else { None })
                    .collect(),
            ]
            .into_iter()
            .flatten()
            .collect();
        }
        let num_rows = num_rows as usize;
        let num_cols = Self::cal_column(s.len(), num_rows);
        let mut matrix: Vec<Vec<char>> = vec![vec!['\n'; num_cols]; num_rows];
        let mut x = 0;
        let mut y = 0;
        let mut down = true;
        let chars: Vec<_> = s.chars().collect();

        for ch in chars {
            matrix[y][x] = ch;

            if down {
                if y == num_rows - 1 {
                    x += 1;
                    y -= 1;
                    down = false;
                } else {
                    y += 1;
                }
            } else {
                if y == 0 {
                    x += 1;
                    y += 1;
                    down = true;
                } else {
                    y -= 1;
                }
            }
        }

        matrix
            .into_iter()
            .flatten()
            .filter(|&ch| ch != '\n')
            .collect()
    }

    fn cal_column(s_len: usize, num_rows: usize) -> usize {
        if num_rows <= 1 {
            return s_len;
        }
        let base = s_len / 2;
        let residue = s_len % (num_rows * 2 - 2);

        if residue == 0 {
            return base;
        } else if residue <= num_rows {
            return base + 1;
        } else {
            return base + 1 + residue - num_rows;
        }
    }
}

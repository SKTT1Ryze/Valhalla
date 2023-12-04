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
                    "test failed for s={s}, num_rows={num_rows}, \
                     expect={expect}, output={output}"
                );
            }
        }

        Ok(())
    }
}

impl SolutionImpl {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows <= 1 {
            return s;
        }
        let num_rows = num_rows as usize;
        let mut matrix: Vec<Vec<char>> = vec![Vec::new(); num_rows];
        let mut y = 0;
        let mut down = true;
        let chars: Vec<_> = s.chars().collect();

        for ch in chars {
            matrix[y].push(ch);

            if down {
                if y == num_rows - 1 {
                    y -= 1;
                    down = false;
                } else {
                    y += 1;
                }
            } else if y == 0 {
                y += 1;
                down = true;
            } else {
                y -= 1;
            }
        }

        matrix.into_iter().flatten().collect()
    }
}

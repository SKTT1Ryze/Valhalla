use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    227,
    "Basic Calculator II",
    ["3+2*2".into(), " 3/2 ".into(), " 3+5 / 2 ".into()],
    [7, 1, 5],
    Self::calculate
);

impl SolutionImpl {
    pub fn calculate(s: String) -> i32 {
        let mut stack = Vec::new();
        let mut prev_sign = '+';
        let mut num = 0;

        for (idx, ch) in s.chars().enumerate() {
            if ch.is_ascii_digit() {
                num = num * 10 + ch.to_digit(10).unwrap() as i32;
            }
            if !ch.is_ascii_digit() && ch != ' ' || idx == s.len() - 1 {
                match prev_sign {
                    '+' => stack.push(num),
                    '-' => stack.push(-num),
                    '*' => *stack.last_mut().unwrap() *= num,
                    '/' => *stack.last_mut().unwrap() /= num,
                    _ => {}
                }
                num = 0;
                prev_sign = ch;
            }
        }

        stack.iter().sum()
    }
}

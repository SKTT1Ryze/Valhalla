use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    65,
    "Valid Number",
    ["0", "e", "."],
    [true, false, false],
    |s| Self::is_number(s.into())
);

impl SolutionImpl {
    pub fn is_number(s: String) -> bool {
        if let Some(e) = s.chars().position(|ch| ch == 'e' || ch == 'E') {
            Self::valid_digit(&s[..e]) && Self::valid_integer(&s[e + 1..])
        } else {
            Self::valid_digit(&s)
        }
    }

    fn valid_digit(s: &str) -> bool {
        let s: Vec<_> = s.chars().collect();
        if s.is_empty() {
            false
        } else {
            let dot = s.iter().position(|&ch| ch == '.');
            if let Some(dot) = dot {
                if dot == 0 {
                    s.len() > 1 && s[1..].iter().all(char::is_ascii_digit)
                } else if dot < s.len() - 1 {
                    Self::valid_head(&s)
                        && s[1..dot].iter().all(char::is_ascii_digit)
                        && s[dot + 1..].iter().all(char::is_ascii_digit)
                } else {
                    Self::valid_head(&s)
                        && s[1..dot].iter().all(char::is_ascii_digit)
                }
            } else {
                Self::valid_head(&s) && s[1..].iter().all(char::is_ascii_digit)
            }
        }
    }

    fn valid_integer(s: &str) -> bool {
        let s: Vec<_> = s.chars().collect();
        if s.is_empty() {
            false
        } else {
            Self::valid_head(&s) && s[1..].iter().all(char::is_ascii_digit)
        }
    }

    fn valid_head(s: &[char]) -> bool {
        (s[0] == '+' || s[0] == '-')
            && s.len() > 1
            && (s.len() == 2 && s[1] != '.' || s.len() > 2)
            || s[0].is_ascii_digit()
    }
}

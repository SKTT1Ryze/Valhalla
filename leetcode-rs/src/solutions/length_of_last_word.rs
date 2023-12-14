use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    58,
    "Length of Last Word",
    [
        "Hello World".into(),
        "   fly me   to   the moon  ".into(),
        "luffy is still joyboy".into()
    ],
    [5, 4, 6],
    Self::length_of_last_word
);

impl SolutionImpl {
    pub fn length_of_last_word(s: String) -> i32 {
        let chars = s.chars();
        let mut ans = 0;
        let mut started = false;

        for ch in chars.rev() {
            if ch == ' ' {
                if started {
                    break;
                }
            } else {
                started = true;
                ans += 1;
            }
        }

        ans
    }
}

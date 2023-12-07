use super::{test_helper, Solution};
use std::collections::HashMap;

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    76,
    "Minimum Window Substring",
    [
        ("ADOBECODEBANC".into(), "ABC".into()),
        ("a".into(), "a".into()),
        ("a".into(), "aa".into())
    ],
    ["BANC".into(), "a".into(), "".into()],
    |(s, t)| Self::min_window(s, t)
);

impl SolutionImpl {
    pub fn min_window(s: String, t: String) -> String {
        let s: Vec<_> = s.chars().collect();
        let mut start = 0;
        let mut end = 0;
        let mut ans = "".into();

        while end < s.len() {
            let mut map: HashMap<char, i32> = HashMap::new();
            let t: Vec<_> = t.chars().collect();

            for ch in t {
                *map.entry(ch).or_default() -= 1;
            }

            while end < s.len() && map.values().any(|&v| v < 0) {
                if let Some(mef) = map.get_mut(&s[end]) {
                    *mef += 1;
                }

                end += 1;
            }

            end -= 1;

            if map.values().any(|&v| v < 0) {
                return ans;
            }

            while start < end {
                let ch = s[start];

                if let Some(mef) = map.get_mut(&ch) {
                    if *mef == 0 {
                        break;
                    }

                    *mef -= 1;
                }

                start += 1;
            }

            if s[start..=end].len() < ans.len() || ans.is_empty() {
                ans = s[start..=end].iter().collect();
            }

            start += 1;
            end = start;
        }

        ans
    }
}

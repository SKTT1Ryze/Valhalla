use super::{test_helper, Solution};
use std::collections::HashMap;

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    44,
    "Wildcard Matching",
    [
        ("aa", "a"),
        ("aa", "*"),
        ("cb", "?a"),
        ("abcabczzzde", "*abc???de*"),
        ("acdcb", "a*c?b"),
        ("leetcode", "*e*t?d*"),
        ("abefcdgiescdfimde", "ab*cd?i*de"),
        ("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"),
    ],
    [false, true, false, true, false, false, true, false],
    |(s, p)| Self::is_match(s.to_string(), p.to_string())
);

impl SolutionImpl {
    pub fn is_match(s: String, p: String) -> bool {
        let s_chars: Vec<char> = s.chars().collect();
        let p_chars: Vec<char> = p.chars().collect();
        let mut memo: HashMap<(usize, usize), bool> = HashMap::new();
        Self::walk(&s_chars, &p_chars, 0, 0, &mut memo)
    }

    pub fn walk(
        s: &[char],
        p: &[char],
        i: usize,
        j: usize,
        memo: &mut HashMap<(usize, usize), bool>,
    ) -> bool {
        if let Some(&result) = memo.get(&(i, j)) {
            return result;
        }

        let result = if i == s.len() && j == p.len() {
            true
        } else if i == s.len() {
            p[j..].iter().all(|&ch| ch == '*')
        } else if j == p.len() {
            false
        } else {
            match p[j] {
                '*' => {
                    if j == p.len() - 1 {
                        true
                    } else if let Some((next, &ch)) =
                        p[j + 1..].iter().enumerate().find(|(_, &e)| e != '*')
                    {
                        if ch == s[i] || ch == '?' {
                            Self::walk(s, p, i, j + next + 1, memo)
                                || Self::walk(s, p, i + 1, j, memo)
                        } else {
                            for (idx, &e) in s[i..].iter().enumerate() {
                                if e == ch && Self::walk(s, p, i + idx, j + next + 1, memo) {
                                    return true;
                                }
                            }
                            false
                        }
                    } else {
                        true
                    }
                }
                '?' => Self::walk(s, p, i + 1, j + 1, memo),
                ch => {
                    if s[i] != ch {
                        false
                    } else {
                        Self::walk(s, p, i + 1, j + 1, memo)
                    }
                }
            }
        };

        memo.insert((i, j), result);
        result
    }
}

use super::{test_helper, Solution};

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Count and Say".into()
    }
    fn problem_id(&self) -> usize {
        38
    }
    fn location(&self) -> String {
        crate::location!()
    }
    fn test(&self) -> anyhow::Result<()> {
        test_helper([1, 4], ["1".into(), "1211".into()], Self::count_and_say)
    }
}

impl SolutionImpl {
    pub fn count_and_say(n: i32) -> String {
        Self::walk("1", n - 1)
    }

    fn walk(s: &str, n: i32) -> String {
        if n > 0 {
            let mut ans = "".to_string();
            let mut stack = Vec::new();
            for ch in s.chars() {
                if !stack.is_empty() {
                    let prev = stack[stack.len() - 1];
                    if prev == ch {
                        stack.push(ch);
                    } else {
                        ans.push_str(&format!("{}{prev}", stack.len()));
                        stack.clear();
                        stack.push(ch);
                    }
                } else {
                    stack.push(ch);
                }
            }
            if !stack.is_empty() {
                ans.push_str(&format!("{}{}", stack.len(), stack[0]));
            }
            Self::walk(&ans, n - 1)
        } else {
            s.to_owned()
        }
    }
}

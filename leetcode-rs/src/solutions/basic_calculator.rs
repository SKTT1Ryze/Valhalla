use std::collections::VecDeque;

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    224,
    "Basic Calculator",
    [
        "1 + 1".into(),
        " 2-1 + 2 ".into(),
        "(1+(4+5+2)-3)+(6+8)".into(),
        "1-11".into()
    ],
    [2, 3, 23, -10],
    Self::calculate
);

enum Item {
    Val(i32),
    Add,
    Sub,
    Left,
}

impl SolutionImpl {
    pub fn calculate(s: String) -> i32 {
        let mut stack: Vec<Item> = Vec::new();
        let mut chars: VecDeque<char> = s.chars().collect();

        let on_add = |curr, stack: &mut Vec<Item>| match stack.pop() {
            Some(Item::Val(other)) => {
                stack.push(Item::Val(other + curr));
            }
            Some(item) => {
                stack.push(item);
                stack.push(Item::Val(curr));
            }
            None => {
                stack.push(Item::Val(curr));
            }
        };
        let on_sub = |curr, stack: &mut Vec<Item>| match stack.pop() {
            Some(Item::Val(other)) => {
                stack.push(Item::Val(other - curr));
            }
            Some(item) => {
                stack.push(item);
                stack.push(Item::Val(0 - curr));
            }
            None => {
                stack.push(Item::Val(0 - curr));
            }
        };
        let on_item = |curr, item, stack: &mut Vec<Item>| {
            stack.push(item);
            stack.push(Item::Val(curr));
        };
        let on_none = |curr, stack: &mut Vec<Item>| stack.push(Item::Val(curr));

        while let Some(ch) = chars.pop_front() {
            match ch {
                '0'..='9' => {
                    let mut curr = ch as i32 - 48;
                    while matches!(chars.front(), Some('0'..='9')) {
                        curr =
                            curr * 10 + chars.pop_front().unwrap() as i32 - 48;
                    }
                    let item = stack.pop();
                    match item {
                        Some(Item::Val(_)) => {
                            panic!()
                        }
                        Some(Item::Add) => on_add(curr, &mut stack),
                        Some(Item::Sub) => on_sub(curr, &mut stack),
                        Some(item) => on_item(curr, item, &mut stack),
                        None => on_none(curr, &mut stack),
                    }
                }
                '+' => stack.push(Item::Add),
                '-' => stack.push(Item::Sub),
                '(' => stack.push(Item::Left),
                ')' => {
                    let curr = match stack.pop() {
                        Some(Item::Val(x)) => x,
                        _ => panic!(),
                    };

                    // must be left
                    assert!(matches!(stack.pop(), Some(Item::Left)));

                    match stack.pop() {
                        Some(Item::Add) => on_add(curr, &mut stack),
                        Some(Item::Sub) => on_sub(curr, &mut stack),
                        Some(item) => on_item(curr, item, &mut stack),
                        None => on_none(curr, &mut stack),
                    }
                }
                _ => {}
            }
        }

        match stack[0] {
            Item::Val(val) => val,
            _ => panic!(),
        }
    }
}

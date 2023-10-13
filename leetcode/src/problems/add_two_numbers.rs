use super::{Difficulty, Problem, Topic};

pub struct AddTwoNumbers;

impl Problem for AddTwoNumbers {
    fn id(&self) -> usize {
        2
    }
    fn difficulty(&self) -> Difficulty {
        Difficulty::Medium
    }
    fn topic(&self) -> Topic {
        Topic::Algorithms
    }
    fn title(&self) -> String {
        "Add Two Numbers".into()
    }
    fn description(&self) -> String {
        r#"You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself."#
            .into()
    }
    fn labels(&self) -> Vec<String> {
        ["Link List".into()].into()
    }
}

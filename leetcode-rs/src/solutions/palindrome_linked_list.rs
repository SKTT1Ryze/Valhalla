use crate::list::ListNode;

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    234,
    "Palindrome Linked List",
    [
        ListNode::create_list([1, 2, 2, 1]),
        ListNode::create_list([1, 2])
    ],
    [true, false],
    Self::is_palindrome
);

impl SolutionImpl {
    pub fn is_palindrome(head: Option<Box<ListNode<i32>>>) -> bool {
        let mut v = Vec::new();
        let mut p = &head;

        while p.is_some() {
            v.push(p.as_ref().unwrap().val);
            p = &p.as_ref().unwrap().next;
        }

        let n = v.len();
        let mut start = 0;
        let mut end = n - 1;

        while start < end {
            if v[start] != v[end] {
                return false;
            }
            start += 1;
            end -= 1;
        }

        true
    }
}

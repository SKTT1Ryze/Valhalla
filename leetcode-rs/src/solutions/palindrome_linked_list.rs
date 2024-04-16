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
        todo!()
    }
}

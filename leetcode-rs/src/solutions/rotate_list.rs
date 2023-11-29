use super::Solution;

use super::list_test_helper;
use crate::list::ListNode;
pub struct SolutionImpl;

crate::derive_list_solution!(
    SolutionImpl,
    61,
    "Rotate List",
    [
        (ListNode::create_list([1, 2, 3, 4, 5]), 2,),
        (ListNode::create_list([0, 1, 2]), 4,)
    ],
    [vec![4, 5, 1, 2, 3], vec![2, 0, 1],],
    |(head, k)| Self::rotate_right(head, k)
);

impl SolutionImpl {
    pub fn rotate_right(
        mut head: Option<Box<ListNode<i32>>>,
        k: i32,
    ) -> Option<Box<ListNode<i32>>> {
        // ref: https://leetcode.com/problems/rotate-list/solutions/3593450/rust-solution-o-1-space-o-n-time/

        // find length of list
        let mut len = 0;

        let mut node_ref = head.as_ref();
        while let Some(node) = node_ref {
            len += 1;
            node_ref = node.next.as_ref();
        }

        if len == 0 {
            return head;
        }

        let k = k % len;

        if k == 0 {
            // nothing to do
            return head;
        }

        // Now I need to remove the last k elements from the list and put them at the
        // head
        let mut node_ref = head.as_deref_mut().unwrap();
        for _ in 0..(len - k - 1) {
            node_ref = node_ref.next.as_deref_mut().unwrap();
        }
        // node_ref now points to the node before the nodes we want to move

        let mut new_head = node_ref.next.take().unwrap();

        // find the end of new_head and connect it to old head
        node_ref = new_head.as_mut();
        while node_ref.next.is_some() {
            node_ref = node_ref.next.as_deref_mut().unwrap();
        }

        node_ref.next = head;

        Some(new_head)
    }
}

use super::Solution;

use crate::list::{assert_eq_list, ListNode};
pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Swap Nodes in Pairs".into()
    }
    fn problem_id(&self) -> usize {
        24
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            (
                ListNode::create_list([1, 2, 3, 4]),
                ListNode::create_list([2, 1, 4, 3]),
            ),
            (ListNode::create_list([]), ListNode::create_list([])),
            (ListNode::create_list([1]), ListNode::create_list([1])),
        ];

        for (head, expect) in testcases {
            let output = Self::swap_pairs(head);

            if !assert_eq_list(&output, &expect) {
                // TODO: print link list
                anyhow::bail!("test failed in Swap Nodes in Pairs solution");
            }
        }

        Ok(())
    }
}

impl SolutionImpl {
    pub fn swap_pairs(mut head: Option<Box<ListNode<i32>>>) -> Option<Box<ListNode<i32>>> {
        let mut res = Box::new(ListNode::new(0));
        let mut p = &mut res;

        while head.is_some() {
            let mut node1 = head.take();
            let mut node2 = node1.as_mut().unwrap().next.take();

            if node2.is_some() {
                head = node2.as_mut().unwrap().next.take();

                node2.as_mut().unwrap().next = node1;
                p.as_mut().next = node2;
                p = p.next.as_mut().unwrap().next.as_mut().unwrap();
            } else {
                p.as_mut().next = node1;
            }
        }

        res.next
    }
}

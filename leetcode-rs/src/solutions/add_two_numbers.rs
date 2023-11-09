use super::Solution;
use crate::list::{assert_eq_list, ListNode};

pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Add Two Numbers Solution".into()
    }
    fn problem_id(&self) -> usize {
        2
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            (
                ListNode::create_list([2, 4, 3]),
                ListNode::create_list([5, 6, 4]),
                ListNode::create_list([7, 0, 8]),
            ),
            (
                ListNode::create_list([0]),
                ListNode::create_list([0]),
                ListNode::create_list([0]),
            ),
            (
                ListNode::create_list([9, 9, 9, 9, 9, 9, 9]),
                ListNode::create_list([9, 9, 9, 9]),
                ListNode::create_list([8, 9, 9, 9, 0, 0, 0, 1]),
            ),
        ];

        for (l1, l2, expect) in testcases {
            let output = Self::add_two_numbers(l1, l2);

            if !assert_eq_list(&expect, &output) {
                // TODO: print link list
                anyhow::bail!("test failed in AddTwoNumbers solution");
            }
        }
        Ok(())
    }
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

impl SolutionImpl {
    pub fn add_two_numbers(
        mut l1: Option<Box<ListNode<i32>>>,
        mut l2: Option<Box<ListNode<i32>>>,
    ) -> Option<Box<ListNode<i32>>> {
        let mut head = None;
        let mut p = &mut head;
        let mut residue = 0;

        while let (Some(node1), Some(node2)) = (l1.as_ref(), l2.as_ref()) {
            let val = (node1.val + node2.val + residue) % 10;
            residue = (node1.val + node2.val + residue) / 10;

            *p = Some(Box::new(ListNode::new(val)));
            p = &mut p.as_mut().unwrap().next;

            l1 = l1.take().unwrap().next;
            l2 = l2.take().unwrap().next;
        }

        while let Some(node) = l1.take() {
            let val = (node.val + residue) % 10;
            residue = (node.val + residue) / 10;

            *p = Some(Box::new(ListNode::new(val)));
            p = &mut p.as_mut().unwrap().next;

            l1 = node.next;
        }

        while let Some(node) = l2.take() {
            let val = (node.val + residue) % 10;
            residue = (node.val + residue) / 10;

            *p = Some(Box::new(ListNode::new(val)));
            p = &mut p.as_mut().unwrap().next;

            l2 = node.next;
        }

        if residue > 0 {
            *p = Some(Box::new(ListNode::new(residue)));
        }

        head
    }
}

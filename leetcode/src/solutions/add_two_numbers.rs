use super::Solution;
use crate::list::{assert_eq_list, ListNode};

pub struct AddTwoNumbers;

impl Solution for AddTwoNumbers {
    fn name(&self) -> String {
        "Add Two Numbers Solution".into()
    }
    fn problem_id(&self) -> usize {
        2
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

impl AddTwoNumbers {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode<i32>>>,
        l2: Option<Box<ListNode<i32>>>,
    ) -> Option<Box<ListNode<i32>>> {
        todo!()
    }
}

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
    fn benchmark(&self) -> anyhow::Result<usize> {
        anyhow::bail!("TODO");
    }
}

impl SolutionImpl {
    pub fn swap_pairs(head: Option<Box<ListNode<i32>>>) -> Option<Box<ListNode<i32>>> {
        todo!()
    }
}

use super::Solution;

use crate::list::{assert_eq_list, ListNode};
pub struct SolutionImpl;

impl Solution for SolutionImpl {
    fn name(&self) -> String {
        "Rotate List".into()
    }
    fn problem_id(&self) -> usize {
        61
    }
    fn location(&self) -> String {
        crate::location!();
    }
    fn test(&self) -> anyhow::Result<()> {
        let testcases = [
            (
                ListNode::create_list([1, 2, 3, 4, 5]),
                2,
                ListNode::create_list([4, 5, 1, 2, 3]),
            ),
            (
                ListNode::create_list([0, 1, 2]),
                4,
                ListNode::create_list([2, 0, 1]),
            ),
        ];

        for (head, k, expect) in testcases {
            let output = Self::rotate_right(head, k);

            if !assert_eq_list(&output, &expect) {
                // TODO: print link list
                anyhow::bail!("test failed in Swap Nodes in Pairs solution");
            }
        }

        Ok(())
    }
}

impl SolutionImpl {
    pub fn rotate_right(head: Option<Box<ListNode<i32>>>, k: i32) -> Option<Box<ListNode<i32>>> {
        todo!()
    }
}

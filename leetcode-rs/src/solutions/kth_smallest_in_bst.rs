use std::{cell::RefCell, rc::Rc};

use crate::btree::{TreeNode, TreeNodeHandle};

use super::{test_helper, Solution};

pub struct SolutionImpl;

crate::derive_solution!(
    SolutionImpl,
    230,
    "Kth Smallest Element in a BST",
    [
        (TreeNodeHandle::from("[3,1,4,null,2]".to_string()).inner, 1),
        (
            TreeNodeHandle::from("[5,3,6,2,4,null,null,1]".to_string()).inner,
            3
        ),
    ],
    [1, 3],
    |(root, k)| Self::kth_smallest(root, k)
);

impl SolutionImpl {
    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        todo!()
    }
}

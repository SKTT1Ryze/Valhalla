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
    pub fn kth_smallest(
        root: Option<Rc<RefCell<TreeNode>>>,
        mut k: i32,
    ) -> i32 {
        Self::in_order_walk(root, &mut k)
    }

    pub fn in_order_walk(
        root: Option<Rc<RefCell<TreeNode>>>,
        k: &mut i32,
    ) -> i32 {
        if let Some(root) = root {
            let left = Self::in_order_walk(root.borrow().left.clone(), k);
            if left != -1 {
                left
            } else {
                *k -= 1;
                if *k == 0 {
                    root.borrow().val
                } else {
                    Self::in_order_walk(root.borrow().right.clone(), k)
                }
            }
        } else {
            -1
        }
    }
}

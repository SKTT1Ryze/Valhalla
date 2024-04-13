use std::{cell::RefCell, rc::Rc};

use crate::btree::TreeNode;

use super::{btree_test_helper, Solution};

pub struct SolutionImpl;

crate::derive_btree_solution!(
    SolutionImpl,
    226,
    "Invert Binary Tree",
    ["[4,2,7,1,3,6,9]", "[2,1,3]", "[]"],
    ["[4,7,2,9,6,3,1]", "[2,3,1]", "[]"],
    Self::invert_tree
);

impl SolutionImpl {
    pub fn invert_tree(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(node) = root {
            let mut new_root = TreeNode::new(node.borrow().val);

            let new_left = Self::invert_tree(node.borrow().right.clone());
            new_root.left = new_left;
            let new_right = Self::invert_tree(node.borrow().left.clone());
            new_root.right = new_right;

            Some(Rc::new(RefCell::new(new_root)))
        } else {
            None
        }
    }
}

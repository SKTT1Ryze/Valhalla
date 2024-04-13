// Definition for a binary tree node

use std::{cell::RefCell, collections::VecDeque, rc::Rc};

pub struct TreeNodeHandle {
    pub inner: Option<Rc<RefCell<TreeNode>>>,
}

impl From<String> for TreeNodeHandle {
    fn from(mut value: String) -> Self {
        value.remove(0);
        value.remove(value.len() - 1);

        let nodes: Vec<&str> = value.split(',').collect();

        if nodes.is_empty() || nodes[0].is_empty() {
            Self { inner: None }
        } else {
            let mut queue = VecDeque::<Rc<RefCell<TreeNode>>>::new();

            let root = Rc::new(RefCell::new(TreeNode::new(
                nodes[0].parse::<i32>().unwrap(),
            )));
            queue.push_back(root.clone());

            for i in (1..nodes.len()).step_by(2) {
                let current = queue.pop_front().unwrap();

                if nodes[i] != "null" {
                    let left_node = Rc::new(RefCell::new(TreeNode::new(
                        nodes[i].parse::<i32>().unwrap(),
                    )));
                    current.borrow_mut().left = Some(left_node.clone());
                    queue.push_back(left_node);
                }

                if i + 1 < nodes.len() && nodes[i + 1] != "null" {
                    let right_node = Rc::new(RefCell::new(TreeNode::new(
                        nodes[i + 1].parse::<i32>().unwrap(),
                    )));
                    current.borrow_mut().right = Some(right_node.clone());
                    queue.push_back(right_node);
                }
            }

            Self { inner: Some(root) }
        }
    }
}

impl PartialEq for TreeNodeHandle {
    fn eq(&self, other: &Self) -> bool {
        self.cmp(other)
    }
}

impl TreeNodeHandle {
    pub fn new(inner: Option<Rc<RefCell<TreeNode>>>) -> Self {
        Self { inner }
    }

    pub fn cmp(&self, other: &Self) -> bool {
        if self.inner.is_some() && other.inner.is_some() {
            let self_ = self.inner.as_ref().unwrap().borrow();
            let other_ = other.inner.as_ref().unwrap().borrow();

            self_.val == other_.val
                && Self::new(self_.left.clone())
                    .cmp(&Self::new(other_.left.clone()))
                && Self::new(self_.right.clone())
                    .cmp(&Self::new(other_.right.clone()))
        } else {
            self.inner.is_none() && other.inner.is_none()
        }
    }

    #[cfg(test)]
    pub fn preorder_cmp(&self, expect: &[i32]) -> bool {
        let mut stack = Vec::<Rc<RefCell<TreeNode>>>::new();
        let mut i = 0;
        let n = expect.len();
        let mut node = self.inner.clone();

        while node.is_some() || !stack.is_empty() {
            if node.is_some() {
                if i < n {
                    if expect[i] != node.as_ref().unwrap().borrow().val {
                        return false;
                    }

                    stack.push(node.as_ref().unwrap().clone());
                    node.clone_from(&node.unwrap().borrow().left);
                    i += 1;
                }
            } else {
                node.clone_from(&stack.pop().unwrap().borrow().right);
            }
        }

        i == n
    }
}

#[derive(Debug)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        Self {
            val,
            left: None,
            right: None,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::TreeNodeHandle;

    #[test]
    fn test_build_tree() -> anyhow::Result<()> {
        let root = TreeNodeHandle::from("[4,2,7,1,3,6,9]".to_string());

        assert!(root.preorder_cmp(&[4, 2, 1, 3, 7, 6, 9]));

        Ok(())
    }
}

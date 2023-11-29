// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode<T: PartialEq + Eq> {
    pub val: T,
    pub next: Option<Box<ListNode<T>>>,
}

impl<T: PartialEq + Eq> ListNode<T> {
    #[inline]
    pub fn new(val: T) -> Self {
        ListNode { next: None, val }
    }

    pub fn create_list<I>(v: I) -> Option<Box<Self>>
    where
        I: IntoIterator<Item = T>,
        <I as IntoIterator>::IntoIter: DoubleEndedIterator,
    {
        let mut head = None;

        for item in v.into_iter().rev() {
            head = Some(Box::new(ListNode {
                val: item,
                next: head,
            }));
        }

        head
    }
}

pub fn assert_eq_list<T: PartialEq + Eq>(
    l1: &Option<Box<ListNode<T>>>,
    l2: &Option<Box<ListNode<T>>>,
) -> bool {
    let mut p1 = l1;
    let mut p2 = l2;
    while let (Some(node1), Some(node2)) = (p1, p2) {
        if node1.val != node2.val {
            return false;
        }
        p1 = &node1.next;
        p2 = &node2.next;
    }

    p1.is_none() && p2.is_none()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_create_list() {
        let v = [1, 3, 2];
        let list = ListNode::create_list(v);

        let mut head = &list;
        let mut v = Vec::from(v);
        while let Some(node) = head {
            let item = v.remove(0);
            assert_eq!(item, node.val);
            head = &node.next;
        }
    }

    #[test]
    fn test_assert_eq_list() {
        let l1 = Some(Box::new(ListNode {
            val: 0,
            next: Some(Box::new(ListNode {
                val: 1,
                next: Some(Box::new(ListNode { val: 2, next: None })),
            })),
        }));
        let l2 = Some(Box::new(ListNode {
            val: 0,
            next: Some(Box::new(ListNode {
                val: 1,
                next: Some(Box::new(ListNode { val: 2, next: None })),
            })),
        }));
        let l3 = Some(Box::new(ListNode {
            val: 0,
            next: Some(Box::new(ListNode {
                val: 1,
                next: Some(Box::new(ListNode { val: 3, next: None })),
            })),
        }));
        let l4 = Some(Box::new(ListNode {
            val: 0,
            next: Some(Box::new(ListNode { val: 1, next: None })),
        }));

        assert!(assert_eq_list(&l1, &l2));
        assert!(!assert_eq_list(&l1, &l3));
        assert!(!assert_eq_list(&l1, &l4));
    }
}

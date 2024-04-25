#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PLowestCommonAncestorBST, 235, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Lowest Common Ancestor of a Binary Search Tree",
    "Given a binary search tree (BST), find the lowest common ancestor (LCA) "
    "node of two given nodes in the BST.",
    {"Binary Tree"});

class SLowestCommonAncestorBST : public ISolution {
 public:
  size_t problemId() const override { return 235; }
  string name() const override {
    return ("Solution for " + string("Lowest Common Ancestor BST"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,
                                 TreeNode* q) const {
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode* target = root;

    if (p->val > q->val) {
      left = q;
      right = p;
    } else {
      left = p;
      right = q;
    }

    while (!(target->val >= left->val && target->val <= right->val)) {
      if (target->val < left->val) target = target->right;
      if (target->val > right->val) target = target->left;
    }

    if (target->val == left->val || target->val == right->val) return target;

    while (true) {
      if (this->isCommonAncestor(target->left, left, true) &&
          this->isCommonAncestor(target->left, right, false)) {
        target = target->left;
      } else if (this->isCommonAncestor(target->right, left, true) &&
                 this->isCommonAncestor(target->right, right, false)) {
        target = target->right;
      } else {
        break;
      }
    }

    return target;
  }

  bool isCommonAncestor(TreeNode* root, TreeNode* node, bool isLeft) const {
    if (root == nullptr) return false;
    if (isLeft) {
      if (root->val == node->val) {
        return true;
      } else {
        return this->isCommonAncestor(root->left, node, isLeft);
      }
    } else {
      if (root->val == node->val) {
        return true;
      } else {
        return this->isCommonAncestor(root->right, node, isLeft);
      }
    }
  }
};

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PLowestCommonAncestorBTree, 236, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Lowest Common Ancestor of a Binary Tree",
    "Given a binary tree, find the lowest common ancestor (LCA) "
    "node of two given nodes in the Binary Tree.",
    {"Binary Tree"});

class SLowestCommonAncestorBTree : public ISolution {
 public:
  size_t problemId() const override { return 236; }
  string name() const override {
    return ("Solution for " + string("Lowest Common Ancestor Binary Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,
                                 TreeNode* q) const {
    if (!root || root->val == p->val || root->val == q->val) return root;

    auto left = this->lowestCommonAncestor(root->left, p, q);
    auto right = this->lowestCommonAncestor(root->right, p, q);

    if (left && right) {
      return root;
    } else if (left) {
      return left;
    } else {
      return right;
    }
  }
};

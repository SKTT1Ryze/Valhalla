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
                                 TreeNode* q) const {}
};

#include "BinaryTree.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PRecoverBST, 99, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Recover Binary Search Tree",
    "You are given the root of a binary search tree (BST), where the values of "
    "exactly two nodes of the tree were swapped by mistake. Recover the tree "
    "without changing its structure.",
    {"Binary Tree"});

class SRecoverBST : public ISolution {
 public:
  size_t problemId() const override { return 99; }
  string name() const override {
    return ("Solution for " + string("Recover Binary Search Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    this->recoverTree(root);
    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  void recoverTree(TreeNode* root) const {}
};

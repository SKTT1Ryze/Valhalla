#include <climits>

#include "BinaryTree.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PValidateBST, 98, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Validate Binary Search Tree",
                        "Given the root of a binary tree, determine if it is a "
                        "valid binary search tree (BST).",
                        {"Binary Tree"});

class SValidateBST : public ISolution {
 public:
  size_t problemId() const override { return 98; }
  string name() const override {
    return ("Solution for " + string("Validate Binary Search Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (this->isValidBST(root)) return 0;
    return 1;
  };
  int benchmark() const override { return 0; }

 private:
  bool isValidBST(TreeNode* root) const {
    return this->isValidBSTHelper(root, LONG_MIN, LONG_MAX);
  }

  bool isValidBSTHelper(TreeNode* node, long long lower,
                        long long upper) const {
    if (node == nullptr) {
      return true;
    }

    int val = node->val;

    if (val <= lower || val >= upper) {
      return false;
    }

    return this->isValidBSTHelper(node->left, lower, val) &&
           this->isValidBSTHelper(node->right, val, upper);
  }
};

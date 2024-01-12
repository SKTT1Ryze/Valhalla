#include "BinaryTree.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PSymmetricTree, 101, DIFFI_EASY, TOPIC_ALGORITHMS, "Symmetric Tree",
    "Given the root of a binary tree, check whether it is a mirror of itself "
    "(i.e., symmetric around its center).",
    {"Binary Tree"});

class SSymmetricTree : public ISolution {
 public:
  size_t problemId() const override { return 101; }
  string name() const override {
    return ("Solution for " + string("Symmetric Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<bool>(
        {"[1,2,2,3,4,4,3]", "[1,2,2,null,3,null,3]"}, {true, false},
        [this](auto root) { return this->isSymmetric(root); });
  };
  int benchmark() const override { return 0; }

 private:
  bool isSymmetric(TreeNode* root) const { return this->check(root, root); }

  bool check(TreeNode* left, TreeNode* right) const {
    if (left && right) {
      return left->val == right->val && this->check(left->left, right->right) &&
             this->check(left->right, right->left);
    } else if (!left && !right) {
      return true;
    } else {
      return false;
    }
  }
};

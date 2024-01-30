#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PBalancedBTree, 110, DIFFI_EASY, TOPIC_ALGORITHMS, "Balanced Binary Tree",
    "Given a binary tree, determine if it i height-balanced.", {"Binary Tree"});

class SBalancedBTree : public ISolution {
 public:
  size_t problemId() const override { return 110; }
  string name() const override {
    return ("Solution for " + string("Balanced Binary Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<bool>(
        {"[3,9,20,null,null,15,7]", "[1,2,2,3,3,null,null,4,4]", "[]"},
        {true, false, true},
        [this](auto root) { return this->isBalanced(root); });
  };
  int benchmark() const override { return 0; }

 private:
  bool isBalanced(TreeNode* root) const {}
};

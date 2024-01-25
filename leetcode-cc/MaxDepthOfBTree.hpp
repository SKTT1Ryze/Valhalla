#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMaxDepthOfBTree, 104, DIFFI_EASY, TOPIC_ALGORITHMS,
    "Maximum Depth of Binary Tree",
    "Given the root of a binary tree, return its maximum depth.A binary tree's "
    "maximum depth is the number of nodes along the longest path from the root "
    "node down to the farthest leaf node.",
    {"Binary Tree"});

class SMaxDepthOfBTree : public ISolution {
 public:
  size_t problemId() const override { return 104; }
  string name() const override {
    return ("Solution for " + string("Maximum Depth of Binary Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<int>(
        {"[3,9,20,null,null,15,7]", "[1,null,2]"}, {3, 2},
        [this](auto root) { return this->maxDepth(root); });
  }
  int benchmark() const override { return 0; }

 private:
  int maxDepth(TreeNode* root) const {}
};

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PBTreeZigzagLevelOrderTraversal, 103, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Binary Tree Zigzag Level Order Traversal",
    "Given the root of a binary tree, return the zigzag level order traversal "
    "of its nodes' values. (i.e., from left to right, then right to left for "
    "the next level and alternate between).",
    {"Binary Tree"});

class SBTreeZigzagLevelOrderTraversal : public ISolution {
 public:
  size_t problemId() const override { return 103; }
  string name() const override {
    return ("Solution for " +
            string("Binary Tree Zigzag Level Order Traversal"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<vector<vector<int>>>(
        {"[3,9,20,null,null,15,7]", "[1]", "[]"},
        {{{3}, {20, 9}, {15, 7}}, {{1}}, {}},
        [this](auto root) { return this->zigzagLevelOrder(root); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) const {}
};

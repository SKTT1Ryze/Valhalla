#include "BinaryTree.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"
#include "util.hpp"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PBTreeLevelOrderTraversal, 102, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Binary Tree Level Order Traversal",
    "Given the root of a binary tree, return the level order traversal of its "
    "nodes' values. (i.e., from left to right, level by level).",
    {"Binary Tree"});

class SBTreeLevelOrderTraversal : public ISolution {
 public:
  size_t problemId() const override { return 102; }
  string name() const override {
    return ("Solution for " + string("Binary Tree Level Order Traversal"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<vector<vector<int>>>(
        {"[3,9,20,null,null,15,7]", "[1]", "[]"},
        {{{3}, {9, 20}, {15, 7}}, {{1}}, {}},
        [this](auto root) { return this->levelOrder(root); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> levelOrder(TreeNode* root) const {}
};

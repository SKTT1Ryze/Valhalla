#include <queue>

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
        {"[3,9,20,null,null,15,7]", "[1]", "[]", "[1,2,3,4,null,null,5]"},
        {{{3}, {20, 9}, {15, 7}}, {{1}}, {}, {{1}, {3, 2}, {4, 5}}},
        [this](auto root) { return this->zigzagLevelOrder(root); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) const {
    if (root == nullptr) return {};
    vector<vector<int>> result;
    if (!root) {
      return result;
    }

    queue<TreeNode*> q;
    q.push(root);
    bool reverseOrder = false;

    while (!q.empty()) {
      int size = q.size();
      vector<int> level;

      for (int i = 0; i < size; ++i) {
        TreeNode* node = q.front();
        q.pop();

        if (reverseOrder) {
          level.insert(level.begin(), node->val);
        } else {
          level.push_back(node->val);
        }

        if (node->left) {
          q.push(node->left);
        }

        if (node->right) {
          q.push(node->right);
        }
      }

      result.push_back(level);
      reverseOrder = !reverseOrder;
    }

    return result;
  }
};

#include <algorithm>
#include <queue>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PBTreeLevelTraversalII, 107, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Binary Tree Level Order Traversal II",
    "Given the root of a binary tree, return the bottom-up level order "
    "traversal of its nodes' values. (i.e., from left to right, level by level "
    "from leaf to root).",
    {"Binary Tree"});

class SBTreeLevelTraversalII : public ISolution {
 public:
  size_t problemId() const override { return 107; }
  string name() const override {
    return ("Solution for " + string("Binary Tree Level Order Traversal II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<vector<vector<int>>>(
        {"[3,9,20,null,null,15,7]", "[1]", "[]"},
        {{{15, 7}, {9, 20}, {3}}, {{1}}, {}},
        [this](auto root) { return this->levelOrderBottom(root); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> levelOrderBottom(TreeNode* root) const {
    if (root == nullptr) return {};
    queue<TreeNode*> current;
    queue<TreeNode*> next;
    vector<vector<int>> ans;
    vector<int> temp;

    current.push(root);

    while (!current.empty() || !next.empty()) {
      if (current.empty()) {
        ans.push_back(temp);
        temp.clear();

        current = next;
        next = {};
      } else {
        auto node = current.front();
        current.pop();

        temp.push_back(node->val);
        if (node->left) next.push(node->left);
        if (node->right) next.push(node->right);
      }
    }

    if (!temp.empty()) ans.push_back(temp);

    reverse(ans.begin(), ans.end());

    return ans;
  }
};

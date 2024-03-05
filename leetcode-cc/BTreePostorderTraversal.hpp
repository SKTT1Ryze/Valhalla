#include <stack>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PBTreePostorderTraversal, 145, DIFFI_EASY,
                        TOPIC_ALGORITHMS, "Binary Tree Postorder Traversal",
                        "Given the root of a binary tree, return the postorder "
                        "traversal of its nodes' values.",
                        {"Binary Tree"});

class SBTreePostorderTraversal : public ISolution {
 public:
  size_t problemId() const override { return 145; }
  string name() const override {
    return ("Solution for " + string("Binary Tree Postorder Traversal"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<vector<int>>(
        {"[1,null,2,3]", "[]", "[1]"}, {{3, 2, 1}, {}, {1}},
        [this](auto root) { return this->postorderTraversal(root); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> postorderTraversal(TreeNode* root) const {
    stack<TreeNode*> s1, s2;
    vector<int> res = {};

    if (!root) return res;

    s1.push(root);

    while (!s1.empty()) {
      auto node = s1.top();
      s1.pop();
      s2.push(node);

      if (node->left) s1.push(node->left);
      if (node->right) s1.push(node->right);
    }

    while (!s2.empty()) {
      res.push_back(s2.top()->val);
      s2.pop();
    }

    return res;
  }
};

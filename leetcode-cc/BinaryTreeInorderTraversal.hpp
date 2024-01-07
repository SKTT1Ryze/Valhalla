#include <stack>

#include "BinaryTree.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"
#include "util.hpp"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PBTreeInorderTraversal, 94, DIFFI_EASY,
                        TOPIC_ALGORITHMS, "Binary Tree Inorder Traversal",
                        "Given the root of a binary tree, return the inorder "
                        "traversal of its nodes' values.",
                        {"BinaryTree"});

class SBTreeInorderTraversal : public ISolution {
 public:
  size_t problemId() const override { return 94; }
  string name() const override {
    return ("Solution for " + string("Binary Tree Inorder Traversal"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    auto output = this->inorderTraversal(root);
    if (!compareVectors(output, {1, 3, 2})) return 1;

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> inorderTraversal(TreeNode* root) const {
    stack<TreeNode*> s = {};
    vector<int> ans = {};
    auto node = root;

    while (node != nullptr || !s.empty()) {
      if (node != nullptr) {
        s.push(node);
        node = node->left;
      } else {
        node = s.top();
        s.pop();
        ans.push_back(node->val);
        node = node->right;
      }
    }

    return ans;
  }
};

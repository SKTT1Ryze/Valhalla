#include "BinaryTree.h"

#include <stack>

using namespace std;

bool preorderCompBTree(TreeNode* root, const vector<int>& expect) {
  stack<TreeNode*> s = {};
  int i = 0;
  int n = expect.size();
  auto node = root;

  while (node != nullptr || !s.empty()) {
    if (node != nullptr) {
      if (i < n) {
        if (expect[i++] != node->val) return false;
        s.push(node);
        node = node->left;
      } else {
        node = s.top();
        s.pop();
        node = node->right;
      }
    }
  }

  return i == n;
}

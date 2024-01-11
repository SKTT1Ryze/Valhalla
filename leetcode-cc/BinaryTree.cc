#include "BinaryTree.h"

#include <queue>
#include <sstream>
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
        return false;
      }
    } else {
      node = s.top();
      s.pop();
      node = node->right;
    }
  }

  return i == n;
}

TreeNode* buildTree(const string& path) {
  stringstream ss(path.substr(1, path.size() - 2));
  vector<string> nodes;
  string token;

  while (getline(ss, token, ',')) {
    nodes.push_back(token);
  }

  if (nodes.empty()) {
    return nullptr;
  }

  queue<TreeNode*> nodeQueue;

  TreeNode* root = new TreeNode(stoi(nodes[0]));
  nodeQueue.push(root);

  for (size_t i = 1; i < nodes.size(); i += 2) {
    TreeNode* current = nodeQueue.front();
    nodeQueue.pop();

    if (nodes[i] != "null") {
      current->left = new TreeNode(stoi(nodes[i]));
      nodeQueue.push(current->left);
    }

    if (i + 1 < nodes.size() && nodes[i + 1] != "null") {
      current->right = new TreeNode(stoi(nodes[i + 1]));
      nodeQueue.push(current->right);
    }
  }

  return root;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
  if (p != nullptr && q != nullptr) {
    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  } else if (p == nullptr && q == nullptr) {
    return true;
  } else {
    return false;
  }
}

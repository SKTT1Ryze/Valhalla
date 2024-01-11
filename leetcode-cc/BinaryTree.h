#pragma once

#include <string>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

bool preorderCompBTree(TreeNode *root, const std::vector<int> &expect);

// Path example: "[3,1,4,null,null,2]"
TreeNode *buildTree(const std::string &path);

bool isSameTree(TreeNode *p, TreeNode *q);

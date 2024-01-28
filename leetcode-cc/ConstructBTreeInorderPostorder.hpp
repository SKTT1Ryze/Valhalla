#include <algorithm>

#include "BinaryTree.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PConstructBTreeInorderPostorder, 106, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Construct Binary Tree from Inorder and Postorder Traversal",
    "Given two integer arrays inorder and postorder where inorder is the "
    "inorder traversal of a binary tree and postorder is the postorder "
    "traversal of the same tree, construct and return the binary tree.",
    {"Binary Tree"});

class SConstructBTreeInorderPostorder : public ISolution {
 public:
  size_t problemId() const override { return 106; }
  string name() const override {
    return (
        "Solution for" +
        string("Construct Binary Tree from Inorder and Postorder Traversal"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    auto root = this->buildTree(inorder, postorder);

    if (!isSameTree(root, ::buildTree("[3,9,20,null,null,15,7]"))) return 1;

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) const {
    unordered_map<int, int> inorder_map;
    for (int i = 0; i < inorder.size(); i++) inorder_map[inorder[i]] = i;

    return this->buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0,
                                 postorder.size() - 1, inorder_map);
  }

  TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                            int in_start, int in_end, int post_start,
                            int post_end,
                            unordered_map<int, int>& inorder_map) const {
    if (in_start > in_end || post_start > post_end) return nullptr;

    int root_val = postorder[post_end];
    TreeNode* root = new TreeNode(root_val);

    int root_index = inorder_map[root_val];
    int left_subtree_size = root_index - in_start;

    root->left = this->buildTreeHelper(
        inorder, postorder, in_start, root_index - 1, post_start,
        post_start + left_subtree_size - 1, inorder_map);
    root->right = this->buildTreeHelper(inorder, postorder, root_index + 1,
                                        in_end, post_start + left_subtree_size,
                                        post_end - 1, inorder_map);

    return root;
  }
};

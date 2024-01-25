#include "BinaryTree.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PConstructBTreePreorderInorder, 105, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Construct Binary Tree from Preorder and Inorder Traversal",
    "Given two integer arrays preorder and inorder where preorder is the "
    "preorder traversal of a binary tree and inorder is the inorder traversal "
    "of the same tree, construct and return the binary tree.",
    {"Binary Tree"});

class SConstructBTreePreorderInorder : public ISolution {
 public:
  size_t problemId() const override { return 105; }
  string name() const override {
    return (
        "Solution for " +
        string("Construct Binary Tree from Preorder and Inorder Traversal"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    auto root = this->buildTree(preorder, inorder);

    if (!isSameTree(root, ::buildTree("[3,9,20,null,null,15,7]"))) return 1;

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) const {
    unordered_map<int, int> inorder_map;
    for (int i = 0; i < inorder.size(); i++) {
      inorder_map[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0,
                           inorder.size(), inorder_map);
  }

  TreeNode* buildTreeHelper(const vector<int>& preorder, int pre_start,
                            int pre_end, const vector<int>& inorder,
                            int in_start, int in_end,
                            unordered_map<int, int>& inorder_map) const {
    if (pre_start == pre_end) {
      return nullptr;
    }

    int root_val = preorder[pre_start];
    TreeNode* root = new TreeNode(root_val);

    int root_index_inorder = inorder_map[root_val];
    int left_tree_size = root_index_inorder - in_start;

    root->left =
        buildTreeHelper(preorder, pre_start + 1, pre_start + 1 + left_tree_size,
                        inorder, in_start, root_index_inorder, inorder_map);

    root->right =
        buildTreeHelper(preorder, pre_start + 1 + left_tree_size, pre_end,
                        inorder, root_index_inorder + 1, in_end, inorder_map);

    return root;
  }
};

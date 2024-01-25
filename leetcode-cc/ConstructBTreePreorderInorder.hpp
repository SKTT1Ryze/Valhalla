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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) const {}
};

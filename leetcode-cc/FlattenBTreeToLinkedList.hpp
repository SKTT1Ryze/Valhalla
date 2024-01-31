#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PFlattenBTreeToLinkedList, 114, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Flatten Binary Tree to Linked List",
    "Given the root of a binary tree, flatten the tree into a linked list",
    {"Binary Tree"});

class SFlattenBTreeToLinkedList : public ISolution {
 public:
  size_t problemId() const override { return 114; }
  string name() const override {
    return ("Solution for " + string("Flatten Binary Tree to Linked List"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTree(
        {"[1,2,5,3,4,null,6]", "[]", "[0]"},
        {"[1,null,2,null,3,null,4,null,5,null,6]", "[]", "[0]"},
        [this](auto root) { return this->flatten(root); });
  };
  int benchmark() const override { return 0; }

 private:
  void flatten(TreeNode* root) const {
    if (root == nullptr) return;
    this->transform(root);
  }

  pair<TreeNode*, TreeNode*> transform(TreeNode* root) const {
    if (root->left == nullptr && root->right == nullptr) {
      return {root, root};
    } else if (root->left == nullptr) {
      auto [head, tail] = this->transform(root->right);
      root->right = head;
      return {root, tail};
    } else if (root->right == nullptr) {
      auto [head, tail] = this->transform(root->left);
      root->right = head;
      root->left = nullptr;
      return {root, tail};
    } else {
      auto [leftHead, leftTail] = this->transform(root->left);
      auto [rightHead, rightTail] = this->transform(root->right);

      root->left = nullptr;
      root->right = leftHead;
      leftTail->right = rightHead;

      return {root, rightTail};
    }
  }
};

#include <stack>

#include "BinaryTree.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PRecoverBST, 99, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Recover Binary Search Tree",
    "You are given the root of a binary search tree (BST), where the values of "
    "exactly two nodes of the tree were swapped by mistake. Recover the tree "
    "without changing its structure.",
    {"Binary Tree"});

class SRecoverBST : public ISolution {
 public:
  size_t problemId() const override { return 99; }
  string name() const override {
    return ("Solution for " + string("Recover Binary Search Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTree({"[1,3,null,null,2]", "[3,1,4,null,null,2]"},
                                {"[3,1,null,null,2]", "[2,1,4,null,null,3]"},
                                [this](auto root) { this->recoverTree(root); });
  };
  int benchmark() const override { return 0; }

 private:
  void recoverTree(TreeNode* root) const {
    stack<TreeNode*> s = {};
    auto node = root;
    TreeNode* node1 = nullptr;
    TreeNode* node2 = nullptr;
    TreeNode* pre = nullptr;

    while (node != nullptr || !s.empty()) {
      if (node) {
        s.push(node);
        node = node->left;
      } else {
        node = s.top();
        s.pop();

        if (pre && node->val <= pre->val) {
          if (!node1) {
            node1 = pre;
          }
          node2 = node;
        }

        pre = node;
        node = node->right;
      }
    }

    swap(node1->val, node2->val);
  }
};

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
  void flatten(TreeNode* root) const {}
};

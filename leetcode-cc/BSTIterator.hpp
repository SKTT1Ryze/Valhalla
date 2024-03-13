#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PBSTIterator, 173, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Binary Search Tree Iterator",
    "Implement the BSTIterator class that represents an iterator over the "
    "in-order traversal of a binary search tree (BST).",
    {"Binary Tree"});

class SBSTIterator : public ISolution {
 public:
  size_t problemId() const override { return 173; }
  string name() const override {
    return ("Solution for " + string("Binary Search Tree Iterator"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  class BSTIterator {
   public:
    BSTIterator(TreeNode* root) {}

    int next() {}

    bool hasNext() {}
  };
};

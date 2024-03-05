#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PBTreePreorderTraversal, 144, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Binary Tree Preorder Traversal",
                        "Given the root of a binary tree, return the preorder "
                        "traversal of its nodes' values.",
                        {"Binary Tree"});

class SBTreePreorderTraversal : public ISolution {
 public:
  size_t problemId() const override { return 144; }
  string name() const override {
    return ("Solution for " + string("Binary Tree Preorder Traversal"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<vector<int>>(
        {"[1,null,2,3]", "[]", "[1]"}, {{1, 2, 3}, {}, {1}},
        [this](auto root) { return this->preorderTraversal(root); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> preorderTraversal(TreeNode* root) const {}
};

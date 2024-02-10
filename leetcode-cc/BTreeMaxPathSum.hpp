#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PBTreeMaxPathSum, 124, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Binary Tree Maximum Path Sum", "", {"Binary Tree"});

class SBTreeMaxPathSum : public ISolution {
 public:
  size_t problemId() const override { return 124; }
  string name() const override {
    return ("Solution for " + string("Binary Tree Maximum Path Sum"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<int>(
        {"[1,2,3]", "[-10,9,20,null,null,15,7]"}, {6, 42},
        [this](auto root) { return this->maxPathSum(root); });
  };
  int benchmark() const override { return 0; }

 private:
  int maxPathSum(TreeNode* root) const {}
};

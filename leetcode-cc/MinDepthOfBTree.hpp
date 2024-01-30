#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PMinDepthOfBTree, 111, DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Minimum Depth of Binary Tree",
                        "Given a binary tree, find its minimum depth.",
                        {"Binary Tree"});

class SMinDepthOfBTree : public ISolution {
 public:
  size_t problemId() const override { return 111; }
  string name() const override {
    return ("Solution for " + string("Minimum Depth of Binary Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<int>(
        {"[3,9,20,null,null,15,7]", "[2,null,3,null,4,null,5,null,6]"}, {2, 5},
        [this](auto root) { return this->minDepth(root); });
  };
  int benchmark() const override { return 0; }

 private:
  int minDepth(TreeNode* root) const {}
};

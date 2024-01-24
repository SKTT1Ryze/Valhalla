#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PPseudoPalindromicPathsInBTree, 1457, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS,
                        "Pseudo-Palindromic Paths in a Binary Tree", "",
                        {"Binary Tree"});

class SPseudoPalindromicPathsInBTree : public ISolution {
 public:
  size_t problemId() const override { return 1457; }
  string name() const override {
    return ("Solution for " +
            string("Pseudo-Palindromic Paths in a Binary Tree"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<int>(
        {"[2,3,1,3,1,null,1]", "[2,1,1,1,3,null,null,null,null,null,1]", "[9]"},
        {2, 1, 1},
        [this](auto root) { return this->pseudoPalindromicPaths(root); });
  };
  int benchmark() const override { return 0; }

 private:
  int pseudoPalindromicPaths(TreeNode* root) const {}
};

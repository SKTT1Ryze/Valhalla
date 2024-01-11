#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PMaxDiffBetNodeAndAncestor, 1026, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS,
                        "Maximum Difference Between Node and Ancestor",
                        "Given the root of a binary tree, find the maximum "
                        "value v for which there exist different nodes a and b "
                        "where v = |a.val - b.val| and a is an ancestor of b.",
                        {"Binary Tree"});

class SMaxDiffBetNodeAndAncestor : public ISolution {
 public:
  size_t problemId() const override { return 1026; }
  string name() const override {
    return ("Solution for " +
            string("Maximum Difference Between Node and Ancestor"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<int>(
        {"[8,3,10,1,6,null,14,null,null,4,7,13]", "[1,null,2,null,0,3]"},
        {7, 3}, [this](auto root) { return this->maxAncestorDiff(root); });
  };
  int benchmark() const override { return 0; }

 private:
  int maxAncestorDiff(TreeNode* root) const {}
};

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PSumRootToLeafNums, 129, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Sum Root to Leaf Numbers", "", {"Binary Tree"});

class SSumRootToLeafNums : public ISolution {
 public:
  size_t problemId() const override { return 129; }
  string name() const override {
    return ("Solution for " + string("Sum Root to Leaf Numbers"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelperBinaryTreeV2<int>(
        {"[1,2,3]", "[4,9,0,5,1]"}, {25, 1026},
        [this](auto root) { return this->sumNumbers(root); });
  };
  int benchmark() const override { return 0; }

 private:
  int sumNumbers(TreeNode* root) const {}
};

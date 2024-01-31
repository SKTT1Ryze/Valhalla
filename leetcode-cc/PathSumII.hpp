#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PPathSumII, 113, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Path Sum II",
    "Given the root of a binary tree and an integer targetSum, return all "
    "root-to-leaf paths where the sum of the node values in the path equals "
    "targetSum. Each path should be returned as a list of the node values, not "
    "node references.",
    {"Binary Tree"});

class SPathSumII : public ISolution {
 public:
  size_t problemId() const override { return 113; }
  string name() const override {
    return ("Solution for " + string("Path Sum II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto root = buildTree("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
    int targetSum = 22;

    auto output = this->pathSum(root, targetSum);
    if (output != vector<vector<int>>({{5, 4, 11, 2}, {5, 8, 4, 5}})) return 1;

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) const {}
};

#include <tuple>

#include "BinaryTree.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PUqBinarySearchTreesII, 95, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Unique Binary Search Trees II",
    "Given an integer n, return all the structurally unique BST's (binary "
    "search trees), which has exactly n nodes of unique values from 1 to n. "
    "Return the answer in any order.",
    {"DP"});

class SUqBinarySearchTreesII : public ISolution {
 public:
  size_t problemId() const override { return 95; }
  string name() const override {
    return ("Solution for " + string("Unique Binary Search Trees II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_tuple(
            3, vector<vector<int>>(
                   {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {3, 1, 2}, {3, 2, 1}})),
        make_tuple(1, vector<vector<int>>{{1}})};

    for (const auto& [n, expect] : testCases) {
      auto output = this->generateTrees(n);
      if (output.size() != expect.size()) return 1;
      for (int i = 0; i < output.size(); i++) {
        if (!preorderCompBTree(output[i], expect[i])) return 1;
      }
    }

    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  vector<TreeNode*> generateTrees(int n) const {}
};

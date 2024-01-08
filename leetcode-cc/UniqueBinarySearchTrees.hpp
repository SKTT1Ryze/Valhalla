#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PUqBinarySearchTrees, 96, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Unique Binary Search Trees",
                        "Given an integer n, return the number of structurally "
                        "unique BST's (binary search trees) which has exactly "
                        "n nodes of unique values from 1 to n.",
                        {""});

class SUqBinarySearchTrees : public ISolution {
 public:
  size_t problemId() const override { return 96; }
  string name() const override {
    return ("Solution for " + string("Unique Binary Search Trees"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, int>(
        {3, 1}, {5, 1}, [this](auto input) { return this->numTrees(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int numTrees(int n) const {}
};

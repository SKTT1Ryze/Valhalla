#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PPascalsTriangleII, 119, DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Pascal's Triangle II",
                        "Given an integer rowIndex, return the rowIndexth "
                        "(0-indexed) row of the Pascal's triangle.",
                        {"Triangle"});

class SPascalsTriangleII : public ISolution {
 public:
  size_t problemId() const override { return 119; }
  string name() const override {
    return ("Solution for " + string("Pascal's Triangle II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, vector<int>>(
        {3, 0, 1}, {{1, 3, 3, 1}, {1}, {1, 1}},
        [this](auto input) { return this->getRow(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> getRow(int rowIndex) const {}
};

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PBitWiseANDOfNumRange, 201, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Bit Wise AND Of Numbers Range",
    "Given two integers left and right that represent the range [left, right], "
    "return the bitwise AND of all numbers in this range, inclusive.",
    {"Bit"});

class SBitWiseANDOfNumRange : public ISolution {
 public:
  size_t problemId() const override { return 201; }
  string name() const override {
    return ("Solution for " + string("Bit Wise AND Of Numbers Range"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<int, int>, int>(
        {{5, 7}, {0, 0}, {1, 2147483647}}, {4, 0, 0}, [this](auto input) {
          return this->rangeBitwiseAnd(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  int rangeBitwiseAnd(int left, int right) const {
    int shift = 0;
    while (left < right) {
      left >>= 1;
      right >>= 1;
      shift++;
    }

    return left << shift;
  }
};

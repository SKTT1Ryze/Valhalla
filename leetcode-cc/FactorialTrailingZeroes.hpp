#include <stack>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PFactorialTrailingZeroes, 172, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Factorial Trailing Zeroes",
    "Given an integer n, return the number of trailing zeroes in n!.",
    {"Math"});

class SFactorialTrailingZeroes : public ISolution {
 public:
  size_t problemId() const override { return 172; }
  string name() const override {
    return ("Solution for " + string("Factorial Trailing Zeroes"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, int>(
        {3, 5, 0, 6, 18}, {0, 1, 0, 1, 3},
        [this](auto input) { return this->trailingZeroes(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int trailingZeroes(int n) const {
    int count = 0;
    while (n > 0) {
      count += n / 5;
      n /= 5;
    }
    return count;
  }
};

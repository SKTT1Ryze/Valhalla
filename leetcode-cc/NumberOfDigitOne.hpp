#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PNumberOfDigitOne, 233, DIFFI_HARD, TOPIC_ALGORITHMS, "Number of Digit One",
    "Given an integer n, count the total number of digit 1 appearing in all "
    "non-negative integers less than or equal to n.",
    {"Math"});

class SNumberOfDigitOne : public ISolution {
 public:
  size_t problemId() const override { return 233; }
  string name() const override {
    return ("Solution for " + string("Number of Digit One"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<int, int>({13, 0}, {6, 0}, [this](auto input) {
      return this->countDigitOne(input);
    });
  };
  int benchmark() const override { return 0; }

 private:
  int countDigitOne(int n) const {
    int count = 0;
    long long factor = 1;

    while (factor <= n) {
      int high = n / (factor * 10);
      int cur = (n / factor) % 10;
      int low = n - (n / factor) * factor;

      if (cur == 0) {
        count += high * factor;
      } else if (cur == 1) {
        count += high * factor + low + 1;
      } else {
        count += (high + 1) * factor;
      }

      factor *= 10;
    }

    return count;
  }
};

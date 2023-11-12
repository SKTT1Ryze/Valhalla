#include "problem.h"
#include "solution.h"

using namespace std;

class PDivideTwoIntegers : public IProblem {
  size_t id() const override { return 29; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "Divide Two Integers"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Math"}; }
};

class SDivideTwoIntegers : public ISolution {
 public:
  size_t problemId() const override { return 29; }
  string name() const override { return "Solution for Divide Two Integers"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_tuple(10, 3, 3),
        make_tuple(7, -3, -2),
    };

    for (const auto& [dividend, divisor, expect] : testCases) {
      auto output = this->divide(dividend, divisor);

      if (output != expect) return 1;
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  int divide(int dividend, int divisor) const {}
};

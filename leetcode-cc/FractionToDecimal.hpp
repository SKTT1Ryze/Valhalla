#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PFractionToDecimal, 166, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Fraction to Recurring Decimal",
    "Given two integers representing the numerator and denominator of a "
    "fraction, return the fraction in string format.",
    {""});

class SFractionToDecimal : public ISolution {
 public:
  size_t problemId() const override { return 166; }
  string name() const override {
    return ("Solution for " + string("Fraction To Recurring Decimal"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<int, int>, string>(
        {{1, 2}, {2, 1}, {4, 333}}, {"0.5", "2", "0.(012)"},
        [this](auto input) {
          return this->fractionToDecimal(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  string fractionToDecimal(int numerator, int denominator) const {}
};

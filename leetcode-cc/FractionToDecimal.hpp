#include <unordered_map>

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
  string fractionToDecimal(int numerator, int denominator) const {
    if (numerator == 0) return "0";

    string result;

    if ((numerator < 0) ^ (denominator < 0)) result += '-';

    long long num = abs((long long)numerator);
    long long den = abs((long long)denominator);

    result += to_string(num / den);

    long long remainder = num % den;
    if (remainder == 0) return result;

    result += '.';

    unordered_map<long long, int> map;
    while (remainder != 0) {
      // begin recurring
      if (map.find(remainder) != map.end()) {
        result.insert(map[remainder], "(");
        result += ')';
        break;
      }

      map[remainder] = result.size();

      remainder *= 10;
      result += to_string(remainder / den);
      remainder %= den;
    }

    return result;
  }
};

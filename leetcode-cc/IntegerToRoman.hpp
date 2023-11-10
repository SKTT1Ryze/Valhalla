#include <utility>

#include "problem.h"
#include "solution.h"

class PIntToRoman : public IProblem {
 public:
  std::size_t id() const override { return 12; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  std::string title() const override { return "Integer to Romain"; }
  std::string description() const override { return ""; }
  std::vector<std::string> labels() const override {
    return {"Math", "String"};
  }
};

class SIntToRoman : public ISolution {
 public:
  std::size_t problemId() const override { return 12; }
  std::string name() const override { return "Solution for Integer to Romain"; }
  std::string location() const override { return __FILE_NAME__; }
  int test() override {
    auto testCases = {std::make_pair(3, "III"), std::make_pair(58, "LVIII"),
                      std::make_pair(1994, "MCMXCIV")};

    for (const auto& [num, expect] : testCases) {
      auto output = this->intToRoman(num);

      if (output != expect) {
        return 1;
      }
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  std::string intToRoman(int num) const {
    std::string res = "";
    auto v = std::vector({
        std::make_pair("I", 1),
        std::make_pair("IV", 4),
        std::make_pair("V", 5),
        std::make_pair("IX", 9),
        std::make_pair("X", 10),
        std::make_pair("XL", 40),
        std::make_pair("L", 50),
        std::make_pair("XC", 90),
        std::make_pair("C", 100),
        std::make_pair("CD", 400),
        std::make_pair("D", 500),
        std::make_pair("CM", 900),
        std::make_pair("M", 1000),
    });

    int i = v.size() - 1;

    while (num > 0) {
      auto roman = num / v[i].second;
      for (int j = 0; j < roman; j++) res += v[i].first;
      num %= v[i].second;
      i--;
    }

    return res;
  }
};

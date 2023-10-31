#include "problem.h"
#include "solution.h"

class PRomanToInt : public IProblem {
 public:
  std::size_t id() const override { return 13; }
  int difficulty() const override { return DIFFI_EASY; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  std::string title() const override { return "Roman to Integer"; }
  std::string description() const override { return ""; }
  std::vector<std::string> labels() const override {
    return {"Math", "String"};
  }
};

class SRomanToInt : public ISolution {
 public:
  std::size_t problemId() const override { return 13; }
  std::string name() const override { return "Solution for Roman to Integer"; }
  std::string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {std::make_pair(3, "III"), std::make_pair(58, "LVIII"),
                      std::make_pair(1994, "MCMXCIV")};

    for (const auto& [expect, num] : testCases) {
      auto output = this->romanToInt(num);

      if (output != expect) {
        return 1;
      }
    }
    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  int romanToInt(std::string s) const { return 0; }
};

#include "problem.h"
#include "solution.h"

using namespace std;

class PLetterCombsOfAPhoneNum : public IProblem {
  size_t id() const override { return 17; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override {
    return "Letter Combinations of a Phone Number";
  }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"String", "Hash Map"}; }
};

class SLetterCombsOfAPhoneNum : public ISolution {
  size_t problemId() const override { return 17; }
  string name() const override {
    return "Solution for Letter Combinations of a Phone Number";
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {
        make_pair<string, vector<string>>(
            "23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}),
        make_pair<string, vector<string>>("", {}),
        make_pair<string, vector<string>>("2", {"a", "b", "c"}),
    };

    for (const auto& [digits, expect] : testCases) {
      auto output = this->letterCombinations(digits);

      if (output != expect) return 1;
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  vector<string> letterCombinations(const string digits) const {}
};

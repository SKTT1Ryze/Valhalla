#include <unordered_map>

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
  vector<string> labels() const override {
    return {"String", "Recursion", "Backtrace"};
  }
};

class SLetterCombsOfAPhoneNum : public ISolution {
  size_t problemId() const override { return 17; }
  string name() const override {
    return "Solution for Letter Combinations of a Phone Number";
  }
  string location() const override { return __FILE_NAME__; }
  int test() override {
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
  vector<string> letterCombinations(const string digits) const {
    if (digits.empty()) return {};
    unordered_map<char, vector<char>> map = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
    };

    vector<string> res = {};
    for (const auto& ch : map.at(digits[0])) {
      walk(res, ch, digits.substr(1, digits.size()), "", map);
    }

    return res;
  }

  static void walk(vector<string>& res, char cur, string digits, string s,
                   const unordered_map<char, vector<char>> map) {
    s.push_back(cur);

    if (digits.empty()) {
      res.push_back(s);
    } else {
      char next = digits[0];
      digits.erase(0, 1);

      for (const auto& ch : map.at(next)) {
        walk(res, ch, digits, s, map);
      }
    }
  }
};

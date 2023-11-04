#include "problem.h"
#include "solution.h"

using namespace std;

class PValidParentheses : public IProblem {
  size_t id() const override { return 20; }
  int difficulty() const override { return DIFFI_EASY; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "Valid Parentheses"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Stack"}; }
};

class SValidParentheses : public ISolution {
 public:
  size_t problemId() const override { return 20; }
  string name() const override { return "Solution for Valid Parentheses"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto testCases = {make_pair("()", true), make_pair("()[]{}", true),
                      make_pair("(]", false)};
    for (const auto& [s, expect] : testCases) {
      auto output = this->isValid(s);

      if (output != expect) return 1;
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  bool isValid(string s) const {
    vector<char> stack = {};

    for (const auto ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        stack.push_back(ch);
      } else {
        if (stack.empty()) return false;
        auto prev = stack[stack.size() - 1];
        if (!((prev == '(' && ch == ')') || (prev == '[' && ch == ']') ||
              (prev == '{' && ch == '}'))) {
          return false;
        }
        stack.pop_back();
      }
    }

    return stack.empty();
  }
};

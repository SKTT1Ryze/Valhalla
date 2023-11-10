#include "problem.h"
#include "solution.h"

using namespace std;

class PGenerateParentheses : public IProblem {
  size_t id() const override { return 22; }
  int difficulty() const override { return DIFFI_MEDIUM; }
  int topic() const override { return TOPIC_ALGORITHMS; }
  string title() const override { return "Generate Parentheses"; }
  string description() const override { return ""; }
  vector<string> labels() const override { return {"Backtracking"}; }
};

class SGenerateParentheses : public ISolution {
 public:
  size_t problemId() const override { return 22; }
  string name() const override { return "Solution for Generate Parentheses"; }
  string location() const override { return __FILE_NAME__; }
  int test() override {
    auto testCases = {
        make_pair<int, vector<string>>(
            3, {"((()))", "(()())", "(())()", "()(())", "()()()"}),
        make_pair<int, vector<string>>(1, {"()"}),
    };

    for (const auto& [n, expect] : testCases) {
      auto output = this->generateParenthesis(n);

      if (output != expect) return 1;
    }

    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  vector<string> generateParenthesis(int n) const {
    vector<string> res = {};

    walk(res, "", n - 1, 1, '(', n);

    return res;
  }

  static void walk(vector<string>& res, string s, int left, int right, char ch,
                   int n) {
    if (s.length() == n * 2) {
      res.push_back(s);
      return;
    }
    s.push_back(ch);
    if (ch == '(') {
      if (left > 0) {
        walk(res, s, left - 1, right + 1, '(', n);
        walk(res, s, left, right - 1, ')', n);
      } else {
        walk(res, s, left, right - 1, ')', n);
      }
    } else {
      if (left > 0 && right > 0) {
        walk(res, s, left - 1, right + 1, '(', n);
        walk(res, s, left, right - 1, ')', n);
      } else if (left > 0) {
        walk(res, s, left - 1, right + 1, '(', n);
      } else {
        walk(res, s, left, right - 1, ')', n);
      }
    }
  }
};

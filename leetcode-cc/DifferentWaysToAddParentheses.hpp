#include <unordered_map>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PDiffWaysToAddParentheses, 241, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Different Ways to Add Parentheses",
    "Given a string expression of numbers and operators, return all possible "
    "results from computing all the different possible ways to group numbers "
    "and operators. You may return the answer in any order.",
    {"Math"});

class SDiffWaysToAddParentheses : public ISolution {
 public:
  size_t problemId() const override { return 241; }
  string name() const override {
    return ("Solution for " + string("Different Ways to Add Parentheses"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, vector<int>>(
        {"2-1-1", "2*3-4*5"}, {{2, 0}, {-34, -10, -14, -10, 10}},
        [this](auto input) { return this->diffWaysToCompute(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> diffWaysToCompute(string expression) const {
    unordered_map<string, vector<int>> memo;
    return this->compute(expression, memo);
  }

  vector<int> compute(const string &expression,
                      unordered_map<string, vector<int>> &memo) const {
    // return the cached result
    if (memo.count(expression)) {
      return memo[expression];
    }

    vector<int> res;
    for (int i = 0; i < expression.size(); i++) {
      char c = expression[i];
      if (c == '+' || c == '-' || c == '*') {
        // divide
        vector<int> left = compute(expression.substr(0, i), memo);
        vector<int> right = compute(expression.substr(i + 1), memo);

        // merge
        for (int l : left) {
          for (int r : right) {
            if (c == '+') {
              res.push_back(l + r);
            } else if (c == '-') {
              res.push_back(l - r);
            } else if (c == '*') {
              res.push_back(l * r);
            }
          }
        }
      }
    }

    if (res.empty()) {
      res.push_back(stoi(expression));
    }

    // cache the result
    memo[expression] = res;
    return res;
  }
};

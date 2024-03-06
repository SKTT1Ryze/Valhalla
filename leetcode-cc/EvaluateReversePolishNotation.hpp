#include <stack>
#include <string>
#include <utility>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PEvaluateReversePolishNotation, 150, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Evaluate Reverse Polish Notation",
    "You are given an array of strings tokens that represents an arithmetic "
    "expression in a Reverse Polish Notation.Evaluate the expression. Return "
    "an integer that represents the value of the expression.",
    {"RPN"});

class SEvaluateReversePolishNotation : public ISolution {
 public:
  size_t problemId() const override { return 150; }
  string name() const override {
    return ("Solution for " + string("Evaluate Reverse Polish Notation"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<string>, int>(
        {{"2", "1", "+", "3", "*"},
         {"4", "13", "5", "/", "+"},
         {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}},
        {9, 6, 22}, [this](auto input) { return this->evalRPN(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int evalRPN(vector<string>& tokens) const {
    stack<int> s = {};

    auto f = [&s]() {
      auto x = s.top();
      s.pop();
      auto y = s.top();
      s.pop();
      return make_pair(x, y);
    };

    for (const auto& token : tokens) {
      if (token == "+") {
        auto [x, y] = f();
        s.push(x + y);
      } else if (token == "-") {
        auto [x, y] = f();
        s.push(y - x);
      } else if (token == "*") {
        auto [x, y] = f();
        s.push(x * y);
      } else if (token == "/") {
        auto [x, y] = f();
        s.push(y / x);
      } else {
        s.push(stoi(token));
      }
    }

    return s.top();
  }
};

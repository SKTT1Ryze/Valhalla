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
    {""});

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
  int evalRPN(vector<string>& tokens) const {}
};

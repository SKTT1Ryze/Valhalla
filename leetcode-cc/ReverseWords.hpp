#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PReverseWords, 151, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Reverse Words in a String",
    "Given an input string s, reverse the order of the words.", {""});

class SReverseWords : public ISolution {
 public:
  size_t problemId() const override { return 151; }
  string name() const override {
    return ("Solution for " + string("Reverse Words in a String"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, string>(
        {"the sky is blue", "  hello world  ", "a good   example"},
        {"blue is sky the", "world hello", "example good a"},
        [this](auto input) { return this->reverseWords(input); });
  };
  int benchmark() const override { return 0; }

 private:
  string reverseWords(string s) const {}
};

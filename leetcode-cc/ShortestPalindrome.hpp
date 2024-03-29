#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PShortestPalindrome, 214, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Shortest Palindrome",
                        "Return the shortest palindrome you can find by "
                        "performing this transformation.",
                        {""});

class SShortestPalindrome : public ISolution {
 public:
  size_t problemId() const override { return 214; }
  string name() const override {
    return ("Solution for " + string("Shortest Palindrome"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, string>(
        {"aacecaaa", "abcd"}, {"aaacecaaa", "dcbabcd"},
        [this](auto input) { return this->shortestPalindrome(input); });
  };
  int benchmark() const override { return 0; }

 private:
  string shortestPalindrome(string s) const {}
};

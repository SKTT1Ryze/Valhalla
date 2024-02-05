#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PValidPalindrome, 125, DIFFI_EASY, TOPIC_ALGORITHMS, "Valid Palindrome",
    "Given a string s, return true if it is a palindrome, or false otherwise.",
    {""});

class SValidPalindrome : public ISolution {
 public:
  size_t problemId() const override { return 125; }
  string name() const override {
    return ("Solution for " + string("Valid Palindrome"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, bool>(
        {"A man, a plan, a canal: Panama", "race a car", " "},
        {true, false, true},
        [this](auto input) { return this->isPalindrome(input); });
  };
  int benchmark() const override { return 0; }

 private:
  bool isPalindrome(string s) const {
    
  }
};

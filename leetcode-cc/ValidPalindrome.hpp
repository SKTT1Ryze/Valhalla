#include <ctype.h>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PValidPalindrome, 125, DIFFI_EASY, TOPIC_ALGORITHMS, "Valid Palindrome",
    "Given a string s, return true if it is a palindrome, or false otherwise.",
    {"String"});

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
    int start = 0;
    int end = s.length();
    while (true) {
      int n = end - start;
      if (n == 0 || n == 1) return true;
      if (!isalnum(s[start])) {
        start++;
      } else if (!isalnum(s[end - 1])) {
        end--;
      } else if (tolower(s[start]) == tolower(s[end - 1])) {
        start++;
        end--;
      } else {
        return false;
      }
    }
  }
};

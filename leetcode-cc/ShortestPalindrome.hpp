#include <algorithm>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PShortestPalindrome, 214, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Shortest Palindrome",
                        "Return the shortest palindrome you can find by "
                        "performing this transformation.",
                        {"Logic / KMP"});

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
  string shortestPalindrome(string s) const {
    int offset = 1;
    int n = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());

    if (s == rev) return s;

    while (offset <= n) {
      char ch = s[s.size() - offset];
      s.insert(s.begin() + offset - 1, ch);
      rev.insert(rev.end() - offset + 1, ch);

      if (s == rev) break;

      offset++;
    }

    return s;
  }
};

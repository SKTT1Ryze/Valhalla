#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PValidAnagram, 242, DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Valid Anagram",
                        "Given two strings s and t, return true if t is an "
                        "anagram of s, and false otherwise.",
                        {"Math"});

class SValidAnagram : public ISolution {
public:
  size_t problemId() const override { return 242; }
  string name() const override {
    return ("Solution for " + string("Valid Anagram"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

  bool isAnagram(string s, string t) {}
};

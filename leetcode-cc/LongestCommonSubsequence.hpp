#include <utility>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PLongestCommonSubsequence, 1143, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Longest Common Subsequence", "",
                        {""});

class SLongestCommonSubsequence : public ISolution {
 public:
  size_t problemId() const override { return 1143; }
  string name() const override {
    return ("Solution for " + string("Longest Common Subsequence"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<string, string>, int>(
        {{"abcde", "ace"}, {"abc", "abc"}, {"abc", "def"}}, {3, 3, 0},
        [this](auto input) {
          return this->longestCommonSubsequence(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  int longestCommonSubsequence(string text1, string text2) const {}
};

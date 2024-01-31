#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PDistinctSubsequences, 115, DIFFI_HARD,
                        TOPIC_ALGORITHMS, "Distinct Subsequences",
                        "Given two strings s and t, return the number of "
                        "distinct subsequences of s which equals t.",
                        {""});

class SDistinctSubsequences : public ISolution {
 public:
  size_t problemId() const override { return 115; }
  string name() const override {
    return ("Solution for " + string("Distinct Subsequences"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<string, string>, int>(
        {{"rabbbit", "rabbit"}, {"babgbag", "bag"}}, {3, 5},
        [this](auto input) {
          return this->numDistinct(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  int numDistinct(string s, string t) const {}
};

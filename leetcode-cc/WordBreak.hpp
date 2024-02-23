#include <utility>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PWordBreak, 139, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Word Break",
    "Given a string s and a dictionary of strings wordDict, return true if s "
    "can be segmented into a space-separated sequence of one or more "
    "dictionary words.",
    {""});

class SWordBreak : public ISolution {
 public:
  size_t problemId() const override { return 139; }
  string name() const override {
    return ("Solution for " + string("Word Break"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<string, vector<string>>, bool>(
        {
            {"leetcode", {"leet", "code"}},
        },
        {true}, [this](auto input) {
          return this->wordBreak(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool wordBreak(string s, vector<string>& wordDict) const {}
};

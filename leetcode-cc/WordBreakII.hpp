#include <utility>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PWordBreakII, 140, DIFFI_HARD, TOPIC_ALGORITHMS, "Word Break II",
    "Given a string s and a dictionary of strings wordDict, add spaces in s to "
    "construct a sentence where each word is a valid dictionary word. Return "
    "all such possible sentences in any order.",
    {""});

class SWordBreakII : public ISolution {
 public:
  size_t problemId() const override { return 149; }
  string name() const override {
    return ("Solution for " + string("Word Break II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<string, vector<string>>, vector<string>>(
        {
            {"catsanddog", {"cat", "cats", "and", "sand", "dog"}},
            {"pineapplepenapple",
             {"apple", "pen", "applepen", "pine", "pineapple"}},

        },
        {{"cats and dog", "cat sand dog"},
         {"pine apple pen apple", "pineapple pen apple",
          "pine applepen apple"}},
        [this](auto input) {
          return this->wordBreak(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  vector<string> wordBreak(string s, vector<string>& wordDict) const {}
};

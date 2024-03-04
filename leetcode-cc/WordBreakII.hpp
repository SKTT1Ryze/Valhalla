#include <numeric>
#include <unordered_set>
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
    {"Backtracking"});

class SWordBreakII : public ISolution {
 public:
  size_t problemId() const override { return 140; }
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
         {"pineapple pen apple", "pine applepen apple",
          "pine apple pen apple"}},
        [this](auto input) {
          return this->wordBreak(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  vector<string> wordBreak(string s, vector<string>& wordDict) const {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<string> current = {};
    vector<string> paths = {};

    this->backtracking(s, 0, 1, dict, current, paths);

    return paths;
  }

  void backtracking(string s, int start, int end, unordered_set<string>& dict,
                    vector<string> current, vector<string>& paths) const {
    int n = s.length();
    if (start < n && end < n) {
      string subs = s.substr(start, end - start);
      if (dict.contains(subs)) {
        this->backtracking(s, start, end + 1, dict, current, paths);
        current.push_back(subs);
        this->backtracking(s, end, end + 1, dict, current, paths);
      } else {
        this->backtracking(s, start, end + 1, dict, current, paths);
      }
    } else {
      if (start < n) {
        if (dict.contains(s.substr(start, n - start))) {
          current.push_back(s.substr(start, n - start));
        } else {
          return;
        }
      }

      if (!current.empty()) {
        string path = accumulate(
            std::next(std::begin(current)), std::end(current), current[0],
            [](string ss, string s) { return ss + " " + s; });

        paths.push_back(path);
      }
    }
  }
};

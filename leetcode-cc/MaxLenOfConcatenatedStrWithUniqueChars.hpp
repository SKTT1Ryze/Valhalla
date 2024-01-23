#include <algorithm>
#include <unordered_set>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMaxLenOfConcatenatedStrWithUniqueChars, 1239, DIFFI_MEDIUM,
    TOPIC_ALGORITHMS,
    "Maximum Length of a Concatenated String with Unique Characters",
    "ou are given an array of strings arr. A string s is formed by the "
    "concatenation of a subsequence of arr that has unique characters.Return "
    "the maximum possible length of s.",
    {"Backtracking"});

class SMaxLenOfConcatenatedStrWithUniqueChars : public ISolution {
 public:
  size_t problemId() const override { return 1239; }
  string name() const override {
    return (
        "Solution for " +
        string(
            "Maximum Length of a Concatenated String with Unique Characters"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<string>, int>(
        {{"un", "iq", "ue"},
         {"cha", "r", "act", "ers"},
         {"abcdefghijklmnopqrstuvwxyz"},
         {"pxa", "ghxqdobesypaz", "rismkaxhlc", "eyxq"}},
        {4, 6, 26, 13}, [this](auto input) { return this->maxLength(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int maxLength(vector<string>& arr) const {
    unordered_set<char> memo;
    return this->backtracking(arr, 0, "", memo);
  }

  int backtracking(vector<string>& arr, int i, string current,
                   unordered_set<char> memo) const {
    if (i == arr.size()) {
      return current.size();
    } else {
      string s = arr[i];
      int notInclued = this->backtracking(arr, i + 1, current, memo);

      for (const auto& ch : s) {
        if (memo.contains(ch)) {
          return notInclued;
        } else {
          memo.insert(ch);
        }
      }

      int included = this->backtracking(arr, i + 1, current + s, memo);

      return max(notInclued, included);
    }
  }
};

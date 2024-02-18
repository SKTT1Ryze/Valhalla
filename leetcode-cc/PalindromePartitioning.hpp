#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PPalindromePartitioning, 131, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Palindrome Partitioning",
    "Given a string s, partition s such that every substring of the partition "
    "is a palindrome. Return all possible palindrome partitioning of s.",
    {"DP / Backtracking"});

class SPalindromePartitioning : public ISolution {
 public:
  size_t problemId() const override { return 131; }
  string name() const override {
    return ("Solution for " + string("Palindrome Partitioning"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, vector<vector<string>>>(
        {"aab", "a"}, {{{"a", "a", "b"}, {"aa", "b"}}, {{"a"}}},
        [this](auto input) { return this->partition(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<string>> partition(string s) const {
    vector<string> current = {};
    vector<vector<string>> paths = {};

    this->backtracking(s, 0, current, paths);

    return paths;
  }

  void backtracking(string& s, int start, vector<string>& current,
                    vector<vector<string>>& paths) const {
    if (start == s.size()) {
      paths.push_back(current);
    } else {
      for (int i = start; i < s.size(); i++) {
        if (this->isPalindrome(s, start, i)) {
          auto substr = s.substr(start, i - start + 1);
          current.push_back(substr);
          this->backtracking(s, i + 1, current, paths);
          current.pop_back();
        }
      }
    }
  }

  bool isPalindrome(string& s, int start, int end) const {
    while (start < end) {
      if (s[start] != s[end]) return false;
      ++start;
      --end;
    }
    return true;
  }
};

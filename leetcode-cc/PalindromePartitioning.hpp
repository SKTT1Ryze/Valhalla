#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PPalindromePartitioning, 131, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Palindrome Partitioning",
    "Given a string s, partition s such that every substring of the partition "
    "is a palindrome. Return all possible palindrome partitioning of s.",
    {""});

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
  vector<vector<string>> partition(string s) const {}
};

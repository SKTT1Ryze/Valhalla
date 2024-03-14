#include <unordered_set>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PRepeatedDNASeq, 187, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Repeated DNA Sequences",
    "Given a string s that represents a DNA sequence, return all the "
    "10-letter-long sequences (substrings) that occur more than once in a DNA "
    "molecule. You may return the answer in any order.",
    {"Hash Table & Sliding Window"});

class SRepeatedDNASeq : public ISolution {
 public:
  size_t problemId() const override { return 187; }
  string name() const override {
    return ("Solution for " + string("Repeated DNA Sequences"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, vector<string>>(
        {"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", "AAAAAAAAAAAAA"},
        {{"CCCCCAAAAA", "AAAAACCCCC"}, {"AAAAAAAAAA"}},
        [this](auto input) { return this->findRepeatedDnaSequences(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<string> findRepeatedDnaSequences(string s) const {
    const int N = 10;
    int n = s.size();
    if (n < N) return {};

    unordered_set<string> res = {};
    unordered_set<string> memo = {};

    for (int i = 0; i <= n - N; i++) {
      auto subs = s.substr(i, N);
      if (memo.contains(subs)) {
        res.insert(subs);
      } else {
        memo.insert(subs);
      }
    }

    return vector(res.begin(), res.end());
  }
};

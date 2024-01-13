#include <numeric>
#include <tuple>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PMinNumStepsMakeTwoStrAnagram, 1347, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS,
                        "Minimum Number of Steps to Make Two Strings Anagram",
                        "", {"String"});

class SMinNumStepsMakeTwoStrAnagram : public ISolution {
 public:
  size_t problemId() const override { return 1347; }
  string name() const override {
    return ("Solution for " +
            string("Minimum Number of Steps to Make Two Strings Anagram"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<string, string>, int>(
        {{"bab", "aba"}, {"leetcode", "practice"}, {"anagram", "mangaar"}},
        {1, 5, 0}, [this](auto input) {
          return this->minSteps(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  int minSteps(string s, string t) const {
    int n = s.size();
    vector<int> map(26, 0);

    for (int i = 0; i < n; i++) map[s[i] - 'a']++;

    for (int i = 0; i < n; i++) {
      if (map[t[i] - 'a'] > 0) {
        map[t[i] - 'a']--;
      }
    }

    return accumulate(map.begin(), map.end(), 0);
  }
};

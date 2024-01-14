#include <tuple>
#include <unordered_map>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PDetIfTwoStrsAreClose, 1657, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Determine if Two Strings Are Close",
                        "", {"String"});

class SDetIfTwoStrsAreClose : public ISolution {
 public:
  size_t problemId() const override { return 1657; }
  string name() const override {
    return ("Solution for " + string("Determine if Two Strings Are Close"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<string, string>, bool>(
        {{"abc", "bca"},
         {"a", "aa"},
         {"cabbba", "abbccc"},
         {"aabbcccddd", "abccccdddd"}},
        {true, false, true, false}, [this](auto input) {
          return this->closeStrings(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool closeStrings(string word1, string word2) const {
    if (word1.size() != word2.size()) return false;
    unordered_map<char, int> map1 = {};
    unordered_map<char, int> map2 = {};

    for (const auto& ch : word1) {
      map1[ch]++;
    }

    for (const auto& ch : word2) {
      map2[ch]++;
    }

    if (map1.size() != map2.size()) return false;

    vector<int> count1, count2;

    for (const auto& [key, value] : map1) {
      count1.push_back(value);
      if (map2.contains(key)) {
        count2.push_back(map2[key]);
      } else {
        return false;
      }
    }

    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());

    return count1 == count2;
  }
};

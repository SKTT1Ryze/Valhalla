#include <unordered_map>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PIsomorphicStrings, 205, DIFFI_EASY, TOPIC_ALGORITHMS, "Isomorphic Strings",
    "Given two strings s and t, determine if they are isomorphic.",
    {"Hash Table"});

class SIsomorphicStrings : public ISolution {
 public:
  size_t problemId() const override { return 205; }
  string name() const override {
    return ("Solution for " + string("Isomorphic Strings"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<string, string>, bool>(
        {{"egg", "add"}, {"foo", "bar"}, {"paper", "title"}},
        {true, false, true}, [this](auto input) {
          return this->isIsomorphic(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool isIsomorphic(string s, string t) const {
    return this->check(s, t) && this->check(t, s);
  }

  bool check(const string& s1, const string& s2) const {
    int m = s1.size();
    int n = s2.size();
    if (m != n) return false;
    unordered_map<char, char> map = {};

    for (int i = 0; i < m; i++) {
      char ch1 = s1[i];
      char ch2 = s2[i];
      if (map.contains(ch1)) {
        if (ch2 != map[ch1]) {
          return false;
        }
      } else {
        map.insert({ch1, ch2});
      }
    }

    return true;
  }
};

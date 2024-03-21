#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PIsomorphicStrings, 205, DIFFI_EASY, TOPIC_ALGORITHMS, "Isomorphic Strings",
    "Given two strings s and t, determine if they are isomorphic.", {""});

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
  bool isIsomorphic(string s, string t) const {}
};

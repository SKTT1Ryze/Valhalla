#include <tuple>

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
        {{"abc", "bca"}, {"a", "aa"}, {"cabbba", "abbccc"}},
        {true, false, true}, [this](auto input) {
          return this->closeStrings(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool closeStrings(string word1, string word2) const {}
};

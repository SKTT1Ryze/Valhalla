#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PCmpVersionNum, 165, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Compare Version Number",
    "Given two version numbers, version1 and version2, compare them.", {""});

class SCmpVersionNum : public ISolution {
 public:
  size_t problemId() const override { return 165; }
  string name() const override {
    return ("Solution for " + string("Compare Version Number"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<string, string>, int>(
        {{"1.01", "1.001"}, {"1.0", "1.0.0"}, {"0.1", "1.1"}}, {0, 0, -1},
        [this](auto input) {
          return this->compareVersion(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  int compareVersion(string version1, string version2) const {}
};

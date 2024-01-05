#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PDecodeWays, 91, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Decode Ways", "", {""});

class SDecodeWays : public ISolution {
 public:
  size_t problemId() const override { return 91; }
  string name() const override { return "Decode Ways"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, int>(
        {"12", "226", "06"}, {2, 3, 0},
        [this](auto input) { return this->numDecodings(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int numDecodings(string s) const {}
};

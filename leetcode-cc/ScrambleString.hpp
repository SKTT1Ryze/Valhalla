#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PScrambleString, 87, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Scramble String", "", {"String"});

class SScrambleString : public ISolution {
 public:
  size_t problemId() const override { return 87; }
  string name() const override { return "Scramble String"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<string, string>, bool>(
        {{"great", "rgeat"}, {"abcde", "caebd"}, {"a", "a"}},
        {true, false, true}, [this](auto input) {
          return this->isScramble(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool isScramble(string s1, string s2) const {}
};

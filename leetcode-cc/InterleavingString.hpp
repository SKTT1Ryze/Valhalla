#include <tuple>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PInterleavingString, 97, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Interleaving String",
                        "Given strings s1, s2, and s3, find whether s3 is "
                        "formed by an interleaving of s1 and s2.",
                        {"String"});

class SInterleavingString : public ISolution {
 public:
  size_t problemId() const override { return 97; }
  string name() const override {
    return ("Solution for " + string("Interleaving String"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<string, string, string>, bool>(
        {make_tuple("aabcc", "dbbca", "aadbbcbcac"),
         make_tuple("aabcc", "dbbca", "aadbbbaccc"), make_tuple("", "", "")},
        {true, false, true}, [this](auto input) {
          return this->isInterleave(get<0>(input), get<1>(input),
                                    get<2>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool isInterleave(string s1, string s2, string s3) const {}
};

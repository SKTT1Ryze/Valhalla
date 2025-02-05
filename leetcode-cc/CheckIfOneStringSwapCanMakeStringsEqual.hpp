#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PCheckIfOneStringSwapCanMakeStringsEqual, 1790,
                        DIFFI_EASY, TOPIC_ALGORITHMS,
                        "Check if One String Swap Can Make Strings Equal", "",
                        {""});

class SCheckIfOneStringSwapCanMakeStringsEqual : public ISolution {
 public:
  size_t problemId() const override { return 1790; }
  string name() const override {
    return ("Solution for " +
            string("Check If One Swap Can Make Strings Equal"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  bool areAlmostEqual(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    int n = s1.size();

    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        for (int j = i + 1; j < n; j++) {
          if (s1[j] == s2[i]) {
            // swap s1[i] and s1[j]
            char tmp = s1[i];
            s1[i] = s1[j];
            s1[j] = tmp;

            if (s1 == s2)
              return true;
            else {
              char tmp = s1[i];
              s1[i] = s1[j];
              s1[j] = tmp;
            }
          }
        }

        return false;
      }
    }

    return true;
  }
};

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PDeterIfStringHalvesAlike, 1704, DIFFI_EASY,
                        TOPIC_ALGORITHMS,
                        "Determine if String Halves Are Alike", "", {"String"});

class SDeterIfStringHalvesAlike : public ISolution {
 public:
  size_t problemId() const override { return 1704; }
  string name() const override {
    return ("Solution for " + string("Determine if String Halves Are Alike"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<string, bool>(
        {"book", "textbook", "MerryChristmas"}, {true, false, false},
        [this](auto input) { return this->halvesAreAlike(input); });
  };
  int benchmark() const override { return 0; }

 private:
  bool halvesAreAlike(string s) const {
    int m = 0;
    int n = 0;
    for (int i = 0; i < s.size() / 2; i++) {
      if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
          s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
          s[i] == 'u' || s[i] == 'U') {
        m++;
      }
      int j = s.size() / 2 + i;
      if (s[j] == 'a' || s[j] == 'A' || s[j] == 'e' || s[j] == 'E' ||
          s[j] == 'i' || s[j] == 'I' || s[j] == 'o' || s[j] == 'O' ||
          s[j] == 'u' || s[j] == 'U') {
        n++;
      }
    }
    return m == n;
  }
};

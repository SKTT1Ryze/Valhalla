#include "problem.h"
#include "solution.h"
#include "util.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PGrayCode, 89, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Gray Code", "", {"Backtracking"});

class SGrayCode : public ISolution {
 public:
  size_t problemId() const override { return 89; }
  string name() const override { return "Solution for Gray Code"; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    vector<tuple<int, vector<int>>> testCases = {
        make_tuple(2, vector<int>({0, 1, 3, 2})),
        make_tuple(1, vector<int>({0, 1}))};

    for (auto& [n, expect] : testCases) {
      auto output = this->grayCode(n);
      if (!compareVectors(output, expect)) {
        return 1;
      }
    }
    return 0;
  }
  int benchmark() const override { return 0; }

 private:
  vector<int> grayCode(int n) const {}
};

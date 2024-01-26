#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(POutOfBoundaryPaths, 576, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Out of Boundary Paths", "", {""});

class SOutOfBoundaryPaths : public ISolution {
 public:
  size_t problemId() const override { return 576; }
  string name() const override {
    return ("Solution for " + string("Out of Boundary Paths"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    int m = 2;
    int n = 2;
    int maxMove = 2;
    int startRow = 0;
    int startColumn = 0;

    auto output = this->findPaths(m, n, maxMove, startRow, startColumn);

    if (output != 6) return 1;
    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  int findPaths(int m, int n, int maxMove, int startRow,
                int startColumn) const {}
};

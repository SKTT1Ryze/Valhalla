#include <utility>
#include <vector>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PSearchA2dMatrixII, 240, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Search a 2D Matrix II",
                        "Write an efficient algorithm that searches for a "
                        "value target in an m x n integer matrix matrix.",
                        {"Matrix"});

class SSearchA2dMatrixII : public ISolution {
 public:
  size_t problemId() const override { return 240; }
  string name() const override {
    return ("Solution for " + string("Search a 2D Matrix II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<std::pair<vector<vector<int>>, int>, bool>(
        {{{{1, 4, 7, 11, 15},
           {2, 5, 8, 12, 19},
           {3, 6, 9, 16, 22},
           {10, 13, 14, 17, 24},
           {18, 21, 23, 26, 30}},
          5}},
        {true}, [this](auto input) {
          return this->searchMatrix(get<0>(input), get<1>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool searchMatrix(vector<vector<int>> &matrix, int target) const {
    int m = matrix.size();
    int n = matrix[0].size();

    int i = 0;
    int j = n - 1;

    while (i < m && j >= 0) {
      auto current = matrix[i][j];
      if (current > target) {
        j--;
      } else if (current < target) {
        i++;
      } else {
        return true;
      }
    }

    return false;
  }
};

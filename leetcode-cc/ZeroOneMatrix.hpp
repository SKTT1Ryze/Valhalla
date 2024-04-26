#include <climits>
#include <queue>
#include <utility>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PZeroOneMatrix, 542, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "01 Matrix",
    "Given an m x n binary matrix mat, return the distance of the nearest 0 "
    "for each cell. The distance between two adjacent cells is 1.",
    {"BFS"});

class SZeroOneMatrix : public ISolution {
 public:
  size_t problemId() const override { return 542; }
  string name() const override {
    return ("Solution for " + string("01 Matrix"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, vector<vector<int>>>(
        {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}},
        {
            {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 1, 0}, {1, 2, 1}},

        },
        [this](auto input) { return this->updateMatrix(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) const {
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> dis(m, vector(n, INT_MAX));
    queue<pair<int, int>> q = {};
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          dis[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      auto [currentX, currentY] = q.front();
      q.pop();

      for (const auto& [dirX, dirY] : dirs) {
        auto nextX = currentX + dirX;
        auto nextY = currentY + dirY;

        if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n &&
            dis[nextX][nextY] > dis[currentX][currentY] + 1) {
          dis[nextX][nextY] = dis[currentX][currentY] + 1;
          q.push({nextX, nextY});
        }
      }
    }

    return dis;
  }
};

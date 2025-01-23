#include <queue>
#include <utility>

#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PMapOfHighestPeak, 1765, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "Map of highest Peak", "", {"Map"});

class SMapOfHighestPeak : public ISolution {
 public:
  size_t problemId() const override { return 1765; }
  string name() const override {
    return ("Solution for " + string("Map of Highest Peak"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
    int m = isWater.size();
    int n = isWater[0].size();

    vector<vector<int>> heights(m, vector(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (isWater[i][j]) {
          heights[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      for (auto &dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];

        if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
            heights[newX][newY] == -1) {
          heights[newX][newY] = heights[x][y] + 1;
          q.push({newX, newY});
        }
      }
    }

    return heights;
  }
};

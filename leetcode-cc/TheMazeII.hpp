#include <climits>
#include <queue>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PTheMazeII, 505, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "The Maze II", "", {"BFS"});

class STheMazeII : public ISolution {
 public:
  size_t problemId() const override { return 505; }
  string name() const override {
    return ("Solution for " + string("The Maze II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<
        tuple<vector<vector<int>>, pair<int, int>, pair<int, int>>, int>(
        {{{
              {0, 0, 1, 0, 0},
              {0, 0, 0, 0, 0},
              {0, 0, 0, 1, 0},
              {1, 1, 0, 1, 1},
              {0, 0, 0, 0, 0},
          },
          {0, 4},
          {4, 4}},
         {{
              {0, 0, 1, 0, 0},
              {0, 0, 0, 0, 0},
              {0, 0, 0, 1, 0},
              {1, 1, 0, 1, 1},
              {0, 0, 0, 0, 0},
          },
          {0, 4},
          {3, 2}}},
        {12, -1}, [this](auto input) {
          return this->shortestDistance(get<0>(input), get<1>(input),
                                        get<2>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  int shortestDistance(const vector<vector<int>>& maze, pair<int, int> start,
                       pair<int, int> destination) const {
    int m = maze.size();
    int n = maze[0].size();

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> memo(m, vector(n, false));

    queue<pair<int, int>> q = {};
    q.push(start);

    vector<vector<int>> dis(m, vector(n, INT_MAX));
    dis[start.first][start.second] = 0;

    while (!q.empty()) {
      if (destination == q.front()) break;
      auto [currentX, currentY] = q.front();
      q.pop();

      memo[currentX][currentY] = true;

      for (const auto& [dirX, dirY] : dirs) {
        auto nextX = currentX + dirX;
        auto nextY = currentY + dirY;
        int delta = 0;

        while (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n &&
               maze[nextX][nextY] != 1) {
          nextX += dirX;
          nextY += dirY;
          delta++;
        }

        nextX -= dirX;
        nextY -= dirY;

        if (!memo[nextX][nextY]) {
          dis[nextX][nextY] = dis[currentX][currentY] + delta;
          q.push({nextX, nextY});
        }
      }
    }

    return dis[destination.first][destination.second];
  }
};

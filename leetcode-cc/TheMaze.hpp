#include <queue>
#include <unordered_set>
#include <utility>

#include "PairHash.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PTheMaze, 490, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "The Maze", "", {"BFS / DFS"});

class STheMaze : public ISolution {
 public:
  size_t problemId() const override { return 490; }
  string name() const override {
    return ("Solution for " + string("The Maze"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<
        tuple<vector<vector<int>>, pair<int, int>, pair<int, int>>, bool>(
        {
            {{
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
             {3, 2}},
        },
        {true, false}, [this](auto input) {
          return this->hasPath(get<0>(input), get<1>(input), get<2>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool hasPath(const vector<vector<int>>& maze, pair<int, int> start,
               pair<int, int> destination) const {
    int m = maze.size();
    int n = maze[0].size();
    queue<pair<int, int>> q = {};
    q.push(start);
    unordered_set<pair<int, int>, pair_hash> memo = {};
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
      auto current = q.front();
      q.pop();

      if (current == destination) {
        return true;
      }

      memo.insert(current);

      for (const auto& [dirX, dirY] : dirs) {
        auto nextX = current.first + dirX;
        auto nextY = current.second + dirY;

        while (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n &&
               maze[nextX][nextY] != 1) {
          nextX += dirX;
          nextY += dirY;
        }

        nextX -= dirX;
        nextY -= dirY;

        if (!memo.contains({nextX, nextY})) {
          q.push({nextX, nextY});
        }
      }
    }

    return false;
  }
};

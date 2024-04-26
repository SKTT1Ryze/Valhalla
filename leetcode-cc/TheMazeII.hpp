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
        {0, -1}, [this](auto input) {
          return this->shortestDistance(get<0>(input), get<1>(input),
                                        get<2>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  int shortestDistance(const vector<vector<int>>& maze, pair<int, int> start,
                       pair<int, int> destination) const {}
};

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PDungeonGame, 174, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Dungeon Game",
                        "Return the knight's minimum initial health so that he "
                        "can rescue the princess.",
                        {""});

class SDungeonGame : public ISolution {
 public:
  size_t problemId() const override { return 174; }
  string name() const override {
    return ("Solution for " + string("Dungeon Game"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, int>(
        {{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}}, {{0}}}, {7, 1},
        [this](auto input) { return this->calculateMinimumHP(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int calculateMinimumHP(vector<vector<int>>& dungeon) const {}
};

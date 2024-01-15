#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PFindPlayersWithZeroOrOneLosses, 2225, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS,
                        "Find Players With Zero or One Losses", "", {""});

class SFindPlayersWithZeroOrOneLosses : public ISolution {
 public:
  size_t problemId() const override { return 2225; }
  string name() const override {
    return ("Solution for " + string("Find Players With Zero or One Losses"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, vector<vector<int>>>(
        {{{1, 3},
          {2, 3},
          {3, 6},
          {5, 6},
          {5, 7},
          {4, 5},
          {4, 8},
          {4, 9},
          {10, 4},
          {10, 9}},
         {{2, 3}, {1, 3}, {5, 4}, {6, 4}}},
        {{{1, 2, 10}, {4, 5, 7, 8}}, {{1, 2, 5, 6}, {}}},
        [this](auto input) { return this->findWinners(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) const {}
};

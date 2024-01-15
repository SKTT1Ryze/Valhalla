#include <algorithm>
#include <unordered_set>

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
  vector<vector<int>> findWinners(vector<vector<int>>& matches) const {
    unordered_set<int> ans0 = {};
    unordered_set<int> ans1 = {};
    unordered_set<int> other = {};

    for (const auto& match : matches) {
      int winner = match[0];
      int loser = match[1];

      if (!other.contains(winner) && !ans1.contains(winner)) {
        ans0.insert(winner);
      }

      if (other.contains(loser)) {
      } else if (ans1.contains(loser)) {
        ans1.erase(loser);
        other.insert(loser);
      } else {
        ans0.erase(loser);
        ans1.insert(loser);
      }
    }

    vector<int> answer0(ans0.begin(), ans0.end());
    vector<int> answer1(ans1.begin(), ans1.end());

    sort(answer0.begin(), answer0.end());
    sort(answer1.begin(), answer1.end());

    return {answer0, answer1};
  }
};

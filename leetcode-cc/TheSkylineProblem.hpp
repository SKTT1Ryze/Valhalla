#include <set>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PTheSkylineProblem, 218, DIFFI_HARD, TOPIC_ALGORITHMS,
    "The Skyline Problem",
    "A city's skyline is the outer contour of the silhouette formed by all the "
    "buildings in that city when viewed from a distance. Given the locations "
    "and heights of all the buildings, return the skyline formed by these "
    "buildings collectively.",
    {"Line Sweep"});

class STheSkylineProblem : public ISolution {
 public:
  size_t problemId() const override { return 218; }
  string name() const override {
    return ("Solution for " + string("The Skyline Problem"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, vector<vector<int>>>(
        {{{0, 2, 3}, {2, 5, 3}},
         {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}}},
        {{{0, 3}, {5, 0}},
         {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}}},
        [this](auto input) { return this->getSkyline(input); });
  };
  int benchmark() const override { return 0; }

 private:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) const {
    vector<vector<int>> result;
    vector<pair<int, int>> points;  // (pos, height) pair
    multiset<int> heights;
    int prevHeight = 0;

    for (auto& building : buildings) {
      // Encode left and right edges with negative and positive heights
      points.emplace_back(building[0], -building[2]);  // left edge
      points.emplace_back(building[1], building[2]);   // right edge
    }

    // Sort points: if x-coordinates are same, sort by height
    sort(points.begin(), points.end());

    heights.insert(0);  // Insert ground level
    for (auto& point : points) {
      if (point.second < 0) {  // Left edge
        heights.insert(-point.second);
      } else {  // Right edge
        heights.erase(heights.find(point.second));
      }

      int currHeight = *heights.rbegin();  // Current max height
      if (currHeight != prevHeight) {
        result.push_back({point.first, currHeight});
        prevHeight = currHeight;
      }
    }

    return result;
  }
};

#include <algorithm>
#include <cstddef>
#include <functional>
#include <unordered_map>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PMaxPointsLine, 149, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Max Points on a Line",
    "Given an array of points where points[i] = [xi, yi] represents a point on "
    "the X-Y plane, return the maximum number of points that lie on the same "
    "straight line.",
    {"Hash Table"});

class SMaxPointsLine : public ISolution {
 public:
  size_t problemId() const override { return 149; }
  string name() const override {
    return ("Solution for " + string("Max Points on a Line"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<vector<int>>, int>(
        {{{1, 1}, {2, 2}, {3, 3}},
         {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}},
        {3, 4}, [this](auto input) { return this->maxPoints(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int maxPoints(vector<vector<int>>& points) const {
    int n = points.size();
    if (n <= 2) return n;

    int res = 0;
    for (int i = 0; i < n; i++) {
      unordered_map<pair<int, int>, int, pair_hash> map = {};

      for (int j = i + 1; j < n; j++) {
        auto slope = getSlope(points[i], points[j]);
        map[slope]++;
      }

      for (const auto& pair : map) {
        res = max(res, pair.second + 1);
      }
    }

    return res;
  }

  struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
      auto h1 = hash<T1>{}(p.first);
      auto h2 = hash<T2>{}(p.first);
      return h1 ^ h2;
    }
  };

  static int getGCD(int a, int b) {
    while (b) {
      int temp = b;
      b = a % b;
      a = temp;
    }

    return a;
  }

  static pair<int, int> getSlope(const vector<int>& p1, const vector<int>& p2) {
    int dx = p2[0] - p1[0];
    int dy = p2[1] - p1[1];
    int gcd = getGCD(dx, dy);
    return {dx / gcd, dy / gcd};
  }
};

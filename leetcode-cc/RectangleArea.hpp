#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PRectangleArea, 223, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Rectangle Area",
    "Given the coordinates of two rectilinear rectangles in a 2D plane, return "
    "the total area covered by the two rectangles.",
    {"Math"});

class SRectangleArea : public ISolution {
 public:
  size_t problemId() const override { return 223; }
  string name() const override {
    return ("Solution for " + string("Rectangle Area"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    auto ans = this->computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
    if (ans != 45) return 1;
    return 0;
  };
  int benchmark() const override { return 0; }

 private:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) const {
    int areaA = (ax2 - ax1) * (ay2 - ay1);
    int areaB = (bx2 - bx1) * (by2 - by1);

    int areaOverlapX = max(0, min(ax2, bx2) - max(ax1, bx1));
    int areaOverlapY = max(0, min(ay2, by2) - max(ay1, by1));

    return areaA + areaB - areaOverlapX * areaOverlapY;
  }
};

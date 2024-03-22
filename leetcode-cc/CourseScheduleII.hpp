#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PCourseScheduleII, 210, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Course Schedule II",
    "Return the ordering of courses you should take to finish all courses. If "
    "there are many valid answers, return any of them. If it is impossible to "
    "finish all courses, return an empty array.",
    {""});

class SCourseScheduleII : public ISolution {
 public:
  size_t problemId() const override { return 210; }
  string name() const override {
    return ("Solution for " + string("Course Schedule II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<int, vector<vector<int>>>, vector<int>>(
        {{2, {{1, 0}}}, {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}}, {1, {}}},
        {{0, 1}, {0, 2, 1, 3}, {0}}, [this](auto input) {
          return this->findOrder(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> findOrder(int numCourses,
                        vector<vector<int>>& prerequisites) const {}
};

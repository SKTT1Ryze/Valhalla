#include <queue>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PCourseSchedule, 207, DIFFI_MEDIUM, TOPIC_ALGORITHMS, "Course Schedule",
    "Return true if you can finish all courses. Otherwise, return false.",
    {"Graph"});

class SCourseSchedule : public ISolution {
 public:
  size_t problemId() const override { return 207; }
  string name() const override {
    return ("Solution for " + string("Course Schedule"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<int, vector<vector<int>>>, bool>(
        {{2, {{1, 0}}}, {2, {{1, 0}, {0, 1}}}}, {true, false},
        [this](auto input) {
          return this->canFinish(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) const {
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adjList(numCourses);

    for (const auto& prerequisite : prerequisites) {
      int course = prerequisite[0];
      int prereq = prerequisite[1];
      adjList[prereq].push_back(course);  // prereq -> course
      indegree[course]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    int count = 0;
    while (!q.empty()) {
      int course = q.front();
      q.pop();
      count++;
      for (int nextCourse : adjList[course]) {
        indegree[nextCourse]--;
        if (indegree[nextCourse] == 0) {
          q.push(nextCourse);
        }
      }
    }

    return count == numCourses;
  }
};

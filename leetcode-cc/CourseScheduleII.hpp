#include <queue>
#include <unordered_map>

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
    {"Graph"});

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
        {{0, 1}, {0, 1, 2, 3}, {0}}, [this](auto input) {
          return this->findOrder(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  vector<int> findOrder(int numCourses,
                        vector<vector<int>>& prerequisites) const {
    unordered_map<int, vector<int>> graph = {};
    vector<int> indegree(numCourses, 0);

    for (const auto& prereq : prerequisites) {
      graph[prereq[1]].push_back(prereq[0]);
      indegree[prereq[0]]++;
    }

    queue<int> q = {};

    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) q.push(i);
    }

    vector<int> path = {};

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      path.push_back(curr);

      for (const auto& after : graph[curr]) {
        indegree[after]--;
        if (indegree[after] == 0) q.push(after);
      }

      graph.erase(curr);
    }

    if (path.size() == numCourses) {
      return path;
    } else {
      return {};
    }
  }
};

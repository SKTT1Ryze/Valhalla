#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PCountServersThatCommunicate, 1267, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Count Servers that Communicate", "",
                        {"Map"});

class SCountServersThatCommunicate : public ISolution {
 public:
  size_t problemId() const override { return 1267; }
  string name() const override {
    return ("Solution for " + string("Count Servers that Communicate"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }

 private:
  int countServers(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;

    vector<int> rows(m, 0);
    vector<int> cols(n, 0);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          rows[i]++;
          cols[j]++;
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) res++;
      }
    }

    return res;
  }
};

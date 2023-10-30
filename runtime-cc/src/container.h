#include <functional>
#include <mutex>
#include <unordered_map>

#include "../leetcode-cc/problem.h"
#include "../leetcode-cc/solution.h"

#define ERROR_REGI_PROB 1
#define ERROR_REGI_SOLU 2

using ArcProblem = std::shared_ptr<Problem>;
using ArcSolution = std::shared_ptr<Solution>;
using ProblemsMap = std::unordered_map<std::size_t, ArcProblem>;
using SolutionsMap = std::unordered_map<std::size_t, std::vector<ArcSolution>>;

class Container {
 public:
  const int registerProblem(std::function<ArcProblem()> f);
  const int registerSolution(std::function<ArcSolution()> f);
  ProblemsMap getProblems();
  std::vector<ArcSolution> getSolutionsById(std::size_t id);

 private:
  ProblemsMap problems;
  SolutionsMap solutions;
  std::mutex mtx;
};
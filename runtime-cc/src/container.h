#include <functional>
#include <mutex>
#include <unordered_map>

#include "../leetcode-cc/problem.h"
#include "../leetcode-cc/solution.h"

#define ERROR_REGI_PROB 1
#define ERROR_REGI_SOLU 2

using ProblemsMap = std::unordered_map<std::size_t, std::shared_ptr<Problem>>;
using SolutionsMap =
    std::unordered_map<std::size_t, std::vector<std::shared_ptr<Solution>>>;

class Container {
 public:
  const int registerProblem(std::function<Problem()> f);
  const int registerSolution(std::function<Solution()> f);
  std::shared_ptr<ProblemsMap> getProblems();
  std::shared_ptr<SolutionsMap> getSolutionsById(std::size_t id);

 private:
  ProblemsMap problems;
  SolutionsMap solutions;
  std::mutex mtx;
};
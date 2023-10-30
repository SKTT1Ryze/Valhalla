#include "container.h"

const int Container::registerProblem(std::function<Problem()> f) {
  auto problem = std::make_shared<Problem>(f());
  this->mtx.lock();
  this->problems.insert(std::make_pair(problem->id(), problem));
  this->mtx.unlock();
  return 0;
}

const int Container::registerSolution(std::function<Solution()> f) {
  auto solution = std::make_shared<Solution>(f());
  this->mtx.lock();
  auto it = this->solutions.find(solution->problemId());
  if (it != solutions.end()) {
    it->second.push_back(solution);
  } else {
    auto v = {solution};
    this->solutions.insert(std::make_pair(solution->problemId(), v));
  }
  this->mtx.unlock();
  return 0;
}

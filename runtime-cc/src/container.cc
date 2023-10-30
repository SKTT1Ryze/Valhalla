#include "container.h"

const int Container::registerProblem(std::function<ArcProblem()> f) {
  auto problem = f();
  this->mtx.lock();
  this->problems.insert(std::make_pair(problem->id(), problem));
  this->mtx.unlock();
  return 0;
}

const int Container::registerSolution(std::function<ArcSolution()> f) {
  auto solution = f();
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

ProblemsMap Container::getProblems() {
  this->mtx.lock();
  auto newMap = this->problems;
  this->mtx.unlock();
  return newMap;
}

std::vector<ArcSolution> Container::getSolutionsById(std::size_t id) {
  this->mtx.lock();
  auto solutions = this->solutions.at(id);
  this->mtx.unlock();
  return solutions;
}

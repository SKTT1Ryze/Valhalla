#include "registration.h"

#include "../leetcode-cc/example.h"

const int registerAll(std::shared_ptr<Container> handle) {
  handle->registerProblem(
      []() -> ArcProblem { return std::make_shared<PExample>(); });
  handle->registerSolution(
      []() -> ArcSolution { return std::make_shared<SExample>(); });

  return 0;
}
#include <fstream>
#include <iostream>

#include "container.h"
#include "error.h"
#include "registration.h"
#include "serder.h"

using namespace nlohmann;

int main() {
  auto containerHandle = std::make_shared<Container>();

  auto ret = registerAll(containerHandle);
  if (ret != 0) {
    std::cerr << "registerAll error, code = " << ret << std::endl;
    return ret;
  }

  auto problems = containerHandle->getProblems();
  json undeads = {};
  for (const auto& [id, problem] : problems) {
    auto title = problem->title();
    std::cout << "Finding solutions for problem No." << id
              << ", title: " << title << "..." << std::endl;

    auto undead = Undead(problem);

    auto solutions = containerHandle->getSolutionsById(id);
    if (solutions.empty()) {
      std::cerr << "No solutions found for problem No." << id << std::endl;
      return ERR_NO_SOLU;
    } else {
      std::cout << "Found solutions, run testcases..." << std::endl;

      for (const auto& solution : solutions) {
        auto ret = solution->test();
        if (ret != 0) {
          std::cerr << "Test for solution [" << solution->name() << "] failed!"
                    << std::endl;
          return ret;
        } else {
          std::cout << "Test for solution [" << solution->name() << "] passed!"
                    << std::endl;

          undead.solutions.push_back(solution->location());
        }
      }
    }

    undeads.push_back(undead.serialization());
  }

  std::ofstream file("undeads.json");
  if (file.is_open()) {
    file << undeads.dump() << std::endl;
    file.close();

    std::cout << "Write undeads.json succeed!" << std::endl;
  } else {
    return ERR_OPEN_FILE;
  }

  return 0;
}

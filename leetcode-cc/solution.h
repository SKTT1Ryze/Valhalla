#pragma once

#include <algorithm>
#include <cstddef>
#include <functional>
#include <string>
#include <vector>

#define ERROR_TEST_FAILED 1

class ISolution {
 public:
  virtual std::size_t problemId() const = 0;
  virtual std::string name() const = 0;
  virtual std::string location() const = 0;
  virtual int test() const = 0;
  virtual int benchmark() const = 0;
  virtual ~ISolution() {}
};

template <typename T, typename N>
int testHelper(std::vector<T> Inputs, std::vector<N> Expects,
               std::function<N(T)> function) {
  int n = std::min(Inputs.size(), Expects.size());
  for (int i = 0; i < n; i++) {
    auto output = function(Inputs[i]);
    if (output != Expects[i]) return 1;
  }
  return 0;
}

#pragma once

#include <cstddef>
#include <string>

#define ERROR_TEST_FAILED 1

class ISolution {
 public:
  virtual std::size_t problemId() const = 0;
  virtual std::string name() const = 0;
  virtual std::string location() const = 0;
  virtual int test() = 0;
  virtual int benchmark() const = 0;
  virtual ~ISolution() {}
};

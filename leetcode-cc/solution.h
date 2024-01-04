#pragma once

#include <algorithm>
#include <cstddef>
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

/**
class S : public ISolution {
 public:
  size_t problemId() const override { return; }
  string name() const override { return ""; }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<>(, , [this](auto input) { return this->; });
  };
  int benchmark() const override { return 0; }

 private:
};
**/

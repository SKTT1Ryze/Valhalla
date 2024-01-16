#include <ctime>
#include <unordered_map>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PInsertDeleteGetrandO1, 380, DIFFI_MEDIUM,
                        TOPIC_ALGORITHMS, "Insert Delete GetRandom O(1)", "",
                        {"Randomized"});

class SInsertDeleteGetrandO1 : public ISolution {
 public:
  size_t problemId() const override { return 380; }
  string name() const override {
    return ("Solution for " + string("Insert Delete GetRandom O(1)"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }
};

class RandomizedSet {
 public:
  RandomizedSet() { srand(time(nullptr)); }

  bool insert(int val) {
    if (indexMap.contains(val)) {
      return false;
    }

    nums.push_back(val);
    indexMap[val] = nums.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (!indexMap.contains(val)) {
      return false;
    }

    int idx = indexMap[val];
    int lastVal = nums.back();

    nums[idx] = lastVal;
    indexMap[lastVal] = idx;

    nums.pop_back();
    indexMap.erase(val);
    return true;
  }

  int getRandom() {
    int randomIndex = rand() % nums.size();
    return nums[randomIndex];
  }

 private:
  vector<int> nums;
  unordered_map<int, int> indexMap;
};

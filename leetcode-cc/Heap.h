#include <memory.h>

#include <vector>

template <typename T>
class Heap {
 private:
  std::vector<T> inner;

  void floatUp(int index) {
    while (index > 0 && inner[index] > inner[(index - 1) / 2]) {
      std::swap(inner[index], inner[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }
  void sinkDown(int index) {
    int n = inner.size();
    while (index * 2 + 1 < n) {
      int child = index * 2 + 1;
      if (child + 1 < n && inner[child + 1] > inner[child]) child++;
      if (inner[index] < inner[child]) {
        std::swap(inner[index], inner[child]);
        index = child;
      } else {
        break;
      }
    }
  }

 public:
  void insert(T value);
  void pop();
  T top();
};

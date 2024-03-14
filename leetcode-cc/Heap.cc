#include "Heap.h"

template <typename T>
void Heap<T>::insert(T value) {
  inner.push_back(value);
  floatUp(inner.size() - 1);
}

template <typename T>
void Heap<T>::pop() {
  if (!inner.empty()) {
    std::swap(inner[0], inner[inner.size() - 1]);
    inner.pop_back();
    sinkDown(0);
  }
}

template <typename T>
T Heap<T>::top() {
  return inner[0];  // panic if inner is empty
}

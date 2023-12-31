#pragma once

#include <functional>
#include <vector>

#include "LinkList.h"

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

int testHelperLinkList(std::vector<std::vector<int>> Inputs,
                       std::vector<std::vector<int>> Expects,
                       std::function<ListNode*(ListNode*)> function);

#include <numeric>
#include <stack>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(
    PSumOfSubArrayMin, 907, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
    "Sum of Subarray Minimums",
    "Given an array of integers arr, find the sum of min(b), where b ranges "
    "over every (contiguous) subarray of arr. Since the answer may be large, "
    "return the answer modulo 10^9 + 7.",
    {"Stack"});

class SSumOfSubArrayMin : public ISolution {
 public:
  size_t problemId() const override { return 907; }
  string name() const override {
    return ("Solution for " + string("Sum of Subarray Minimums"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<vector<int>, int>(
        {{3, 1, 2, 4}, {11, 81, 94, 43, 3}}, {17, 444},
        [this](auto input) { return this->sumSubarrayMins(input); });
  };
  int benchmark() const override { return 0; }

 private:
  int sumSubarrayMins(vector<int>& arr) const {
    long long ans = 0;
    int n = arr.size();
    vector<int> dp = arr;

    ans += accumulate(dp.begin(), dp.end(), 0);

    for (int i = 1; i < n; i++) {
      vector<int> row;
      for (int j = 0; j < n - i; j++) {
        int m = min(dp[j], arr[i + j]);
        ans += m;
        row.push_back(m);
      }
      dp = row;
    }

    long long p = pow(10, 9) + 7;

    return ans % p;
  }

  int sumSubarrayMinsByChatGPT(vector<int>& arr) const {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    stack<int> st;
    vector<int> left(n), right(n);

    // Calculate the nearest smaller element on the left
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && arr[st.top()] > arr[i]) {
        st.pop();
      }
      left[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    // Clear the stack for the next traversal
    while (!st.empty()) {
      st.pop();
    }

    // Calculate the nearest smaller element on the right
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && arr[st.top()] >= arr[i]) {
        st.pop();
      }
      right[i] = st.empty() ? n : st.top();
      st.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = (ans + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
    }

    return static_cast<int>(ans);
  }
};

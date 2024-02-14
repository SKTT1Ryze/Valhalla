#include <queue>
#include <tuple>
#include <unordered_set>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PWordLadder, 127, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Word Ladder", "", {"BFS"});

class SWordLadder : public ISolution {
 public:
  size_t problemId() const override { return 127; }
  string name() const override {
    return ("Solution for " + string("Word Ladder"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<string, string, vector<string>>, int>(
        {make_tuple("hit", "cog",
                    vector<string>({"hot", "dot", "dog", "lot", "log", "cog"})),
         make_tuple("hit", "cog",
                    vector<string>({"hot", "dot", "dog", "lot", "log"})),
         make_tuple("hot", "dog", vector<string>({"hot", "dog"}))},
        {5, 0, 0}, [this](auto input) {
          return this->ladderLength(get<0>(input), get<1>(input),
                                    get<2>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  int ladderLength(string beginWord, string endWord,
                   vector<string>& wordList) const {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.contains(endWord)) return 0;

    queue<string> q = {};
    q.push(beginWord);

    int ans = 1;

    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        auto word = q.front();
        q.pop();

        for (int j = 0; j < word.size(); j++) {
          char originalChar = word[j];
          for (char c = 'a'; c <= 'z'; ++c) {
            if (c == originalChar) continue;
            word[j] = c;

            if (word == endWord) return ans + 1;
            if (wordSet.contains(word)) {
              q.push(word);
              wordSet.erase(word);
            }
          }
          word[j] = originalChar;
        }
      }
      ans++;
    }

    return 0;
  }
};

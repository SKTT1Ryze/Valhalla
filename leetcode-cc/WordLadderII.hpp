#include <queue>
#include <tuple>
#include <unordered_set>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PWordLadderII, 126, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Word Ladder II", "", {"DFS & BFS"});

class SWordLadderII : public ISolution {
 public:
  size_t problemId() const override { return 126; }
  string name() const override {
    return ("Solution for " + string("Word Ladder II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<tuple<string, string, vector<string>>,
                      vector<vector<string>>>(
        {make_tuple("hit", "cog",
                    vector<string>({"hot", "dot", "dog", "lot", "log", "cog"})),
         make_tuple("hit", "hit",
                    vector<string>({"hot", "dot", "dog", "lot", "log"}))},
        {{{"hit", "hot", "dot", "dog", "cog"},
          {"hit", "hot", "lot", "log", "cog"}},
         {}},
        [this](auto input) {
          return this->findLadders(get<0>(input), get<1>(input), get<2>(input));
        });
  };
  int benchmark() const override { return 0; }

 private:
  // ref:
  // https://leetcode.com/problems/word-ladder-ii/solutions/2421786/c-using-bfs-and-backtracking-no-tle/
  bool able(string s, string t) const {
    int c = 0;
    for (int i = 0; i < s.length(); i++) c += (s[i] != t[i]);
    return c == 1;
  }

  void bfs(vector<vector<int>> &g, vector<int> parent[], int n, int start,
           int end) const {
    vector<int> dist(n, 1005);
    queue<int> q;
    q.push(start);
    parent[start] = {-1};
    dist[start] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int u : g[x]) {
        if (dist[u] > dist[x] + 1) {
          dist[u] = dist[x] + 1;
          q.push(u);
          parent[u].clear();
          parent[u].push_back(x);
        } else if (dist[u] == dist[x] + 1)
          parent[u].push_back(x);
      }
    }
  }

  void shortestPaths(vector<vector<int>> &Paths, vector<int> &path,
                     vector<int> parent[], int node) const {
    if (node == -1) {
      // as parent of start was -1, we've completed the backtrack
      Paths.push_back(path);
      return;
    }
    for (auto u : parent[node]) {
      path.push_back(u);
      shortestPaths(Paths, path, parent, u);
      path.pop_back();
    }
  }

  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) const {
    // start and end are indices of beginWord and endWord
    int n = wordList.size(), start = -1, end = -1;
    vector<vector<string>> ANS;
    for (int i = 0; i < n; i++) {
      if (wordList[i] == beginWord) start = i;
      if (wordList[i] == endWord) end = i;
    }

    // if endWord doesn't exist, return empty list
    if (end == -1) return ANS;

    // if beginWord doesn't exist, add it in start of WordList
    if (start == -1) {
      wordList.emplace(wordList.begin(), beginWord);
      start = 0;
      end++;
      n++;
    }
    // for each word, we're making adjency list of neighbour words (words that
    // can be made with one letter change) Paths will store all the shortest
    // paths (formed later by backtracking)
    vector<vector<int>> g(n, vector<int>()), Paths;

    // storing possible parents for each word (to backtrack later), path is the
    // current sequence (while backtracking)
    vector<int> parent[n], path;

    // creating adjency list for each pair of words in the wordList (including
    // beginword)
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
        if (able(wordList[i], wordList[j])) {
          g[i].push_back(j);
          g[j].push_back(i);
        }

    bfs(g, parent, n, start, end);

    // backtracking to make shortestpaths
    shortestPaths(Paths, path, parent, end);
    for (auto u : Paths) {
      vector<string> now;
      for (int i = 0; i < u.size() - 1; i++) now.push_back(wordList[u[i]]);
      reverse(now.begin(), now.end());
      now.push_back(wordList[end]);
      ANS.push_back(now);
    }
    return ANS;
  }
};

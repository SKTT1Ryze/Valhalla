#include <unordered_set>

#include "PairHash.h"
#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PWordSearchII, 212, DIFFI_HARD, TOPIC_ALGORITHMS,
                        "Word Search II",
                        "Given an m x n board of characters and a list of "
                        "strings words, return all words on the board.",
                        {"Backtracking & Trie"});

class SWordSearchII : public ISolution {
 public:
  size_t problemId() const override { return 212; }
  string name() const override {
    return ("Solution for " + string("Word Search II"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override {
    return testHelper<pair<vector<vector<char>>, vector<string>>,
                      vector<string>>(
        {
            {{{'o', 'a', 'a', 'n'},
              {'e', 't', 'a', 'e'},
              {'i', 'h', 'k', 'r'},
              {'i', 'f', 'l', 'v'}},
             {"oath", "pea", "eat", "rain"}},

        },
        {{"oath", "eat"}}, [this](auto input) {
          return this->findWords(input.first, input.second);
        });
  };
  int benchmark() const override { return 0; }

 private:
  /* Time Limited */
  // vector<string> findWords(vector<vector<char>>& board,
  //                          vector<string>& words) const {
  //   unordered_set<string> wordSet(words.begin(), words.end());
  //   int m = board.size();
  //   int n = board[0].size();
  //   unordered_set<string> res = {};
  //
  //   for (int i = 0; i < m; i++) {
  //     for (int j = 0; j < n; j++) {
  //       string current = {board[i][j]};
  //       unordered_set<string> candidate = {};
  //       unordered_set<pair<int, int>, pair_hash> memo = {{i, j}};
  //
  //       for (const auto& word : wordSet) {
  //         if (word.starts_with(current)) {
  //           candidate.insert(word);
  //         }
  //       }
  //
  //       if (!candidate.empty())
  //         this->backtracking(board, candidate, memo, i, j, current, res);
  //     }
  //   }
  //
  //   return vector(res.begin(), res.end());
  // }
  //
  // void backtracking(vector<vector<char>>& board, unordered_set<string>&
  // words,
  //                   unordered_set<pair<int, int>, pair_hash>& memo, int i,
  //                   int j, string& current, unordered_set<string>& res) const
  //                   {
  //   if (words.empty()) return;
  //
  //   if (words.contains(current)) {
  //     res.insert(current);
  //     words.erase(current);
  //   }
  //
  //   for (const auto& [m, n] :
  //        vector<pair<int, int>>({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})) {
  //     int nextI = i + m;
  //     int nextJ = j + n;
  //
  //     if (!memo.contains({nextI, nextJ}) && nextI >= 0 &&
  //         nextI < board.size() && nextJ >= 0 && nextJ < board[0].size()) {
  //       string next = current + board[nextI][nextJ];
  //       bool exist = false;
  //
  //       for (const auto& word : words) {
  //         if (word.starts_with(next)) exist = true;
  //       }
  //
  //       if (exist) {
  //         memo.insert({nextI, nextJ});
  //         this->backtracking(board, words, memo, nextI, nextJ, next, res);
  //         memo.erase({nextI, nextJ});
  //       }
  //     }
  //   }
  // }

  struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string word;
  };
  vector<string> findWords(vector<vector<char>>& board,
                           vector<string>& words) const {
    buildTrie(words);
    vector<string> result;
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        backtrack(board, root, visited, i, j, result);
      }
    }

    return result;
  }

 private:
  TrieNode* root = new TrieNode();

  void buildTrie(const vector<string>& words) const {
    for (const string& word : words) {
      TrieNode* node = root;
      for (char c : word) {
        if (!node->children.count(c)) {
          node->children[c] = new TrieNode();
        }
        node = node->children[c];
      }
      node->word = word;
    }
  }

  void backtrack(vector<vector<char>>& board, TrieNode* node,
                 vector<vector<bool>>& visited, int i, int j,
                 vector<string>& result) const {
    if (!node || visited[i][j] || !node->children.count(board[i][j])) {
      return;
    }

    char c = board[i][j];
    node = node->children[c];

    if (!node->word.empty()) {
      result.push_back(node->word);
      node->word = "";  // Mark as visited to avoid duplicates
    }

    visited[i][j] = true;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (const auto& dir : directions) {
      int ni = i + dir.first, nj = j + dir.second;
      if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
        backtrack(board, node, visited, ni, nj, result);
      }
    }
    visited[i][j] = false;  // Backtrack
  }
};

#include <unordered_map>

#include "TestHelper.h"
#include "problem.h"
#include "solution.h"

using namespace std;

IMPLEMENT_PROBLEM_CLASS(PLRUCache, 146, DIFFI_MEDIUM, TOPIC_ALGORITHMS,
                        "LRU Cache",
                        "Design a data structure that follows the constraints "
                        "of a Least Recently Used (LRU) cache.",
                        {"Hash Table & Double Linked List"});

class SLRUCache : public ISolution {
 public:
  size_t problemId() const override { return 146; }
  string name() const override {
    return ("Solution for " + string("LRU Cache"));
  }
  string location() const override { return __FILE_NAME__; }
  int test() const override { return 0; };
  int benchmark() const override { return 0; }
};

struct DListNode {
  int key;
  int val;
  DListNode* prev;
  DListNode* next;
  DListNode() : key(-1), val(-1), prev(nullptr), next(nullptr) {}
  DListNode(int key, int val)
      : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->head = new DListNode();
    this->tail = new DListNode();
    this->head->next = tail;
    this->tail->prev = head;
  }

  int get(int key) {
    if (this->inner.contains(key)) {
      auto node = this->inner[key];
      this->moveToHead(node);
      return node->val;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (this->inner.contains(key)) {
      auto node = this->inner[key];
      node->val = value;
      this->moveToHead(node);
    } else {
      if (this->inner.size() >= capacity) {
        auto tail = this->removeTail();
        this->inner.erase(tail->key);
        delete tail;
      }
      auto node = new DListNode(key, value);
      this->inner.insert({key, node});
      this->addNodeToHead(node);
    }
  }

 private:
  unordered_map<int, DListNode*> inner = {};
  DListNode* head;
  DListNode* tail;
  int capacity;

  static void removeNode(DListNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addNodeToHead(DListNode* node) {
    node->next = this->head->next;
    this->head->next->prev = node;
    this->head->next = node;
    node->prev = this->head;
  }

  void moveToHead(DListNode* node) {
    removeNode(node);
    this->addNodeToHead(node);
  }

  DListNode* removeTail() {
    auto node = tail->prev;
    removeNode(node);
    return node;
  }
};

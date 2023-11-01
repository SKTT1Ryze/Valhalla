#include <memory>
#include <unordered_map>

template <typename T, typename R>
class TireNode {
 public:
  TireNode(R value) { this->value = value; }
  void insertChild(T key, R value) {
    this->children.insert(
        std::make_pair(key, std::make_shared<TireNode>(TireNode(value))));
  }
  std::shared_ptr<TireNode<T, R>> getChild(const T& key) {
    return this->children.at(key);
  }
  bool hasChild(const T& key) { return this->children.contains(key); }

  R value;

 private:
  std::unordered_map<T, std::shared_ptr<TireNode<T, R>>> children;
};

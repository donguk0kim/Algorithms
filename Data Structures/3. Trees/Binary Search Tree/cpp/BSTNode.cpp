#include "BSTNode.hpp"

/* constructor */
BSTNode::BSTNode(int value) :
  value{value},
  left{nullptr},
  rite{nullptr} {
}

BSTNode::~BSTNode() {
  if (left) delete left;
  if (rite) delete rite;
}

/* basic operations */
BSTNode* BSTNode::max() {
  BSTNode* node = this;
  while (node->rite) {
    node = node->rite;
  }
  return node;
}

bool BSTNode::unbound() const {
  return (left == nullptr) && (rite == nullptr);
}

void BSTNode::append(BSTNode* node) {
  if (node->value <= value) {
    if (left) left->append(node);
    if (left == nullptr) left = node;
    
  } else {
    if (rite) rite->append(node);
    if (rite == nullptr) rite = node;
  }
}

std::vector<BSTNode*> BSTNode::children() const {
  std::vector<BSTNode*> children;
  if (left) children.push_back(left);
  if (rite) children.push_back(rite);
  return children;
}

/* traversal */
std::vector<BSTNode*> BSTNode::bfs() {
  BSTNode* node;
  std::vector<BSTNode*> children;
  std::vector<BSTNode*> queue { this };
  std::vector<BSTNode*> order { this };

  while (!queue.empty()) {
    node = queue[0];
    queue.erase(queue.begin());
    children = node->children();

    for (int index = 0; index < children.size(); index++) {
      queue.push_back(children[index]);
      order.push_back(children[index]);
    }
  }
  
  return order;
}

void BSTNode::dfs(std::vector<BSTNode*>& order) {
  BSTNode* child;
  order.push_back(this);
  std::vector<BSTNode*> children = this->children();
  for (int index = 0; index < children.size(); index++) {
    child = children[index];
    child->dfs(order);
  }
}

/* debugger */
void BSTNode::printBFS() {
  std::vector<BSTNode*> order = bfs();

  std::cout << "{ ";
  for (int index = 0; index < order.size(); index++) {
    std::cout << order[index]->value;
    if (index < order.size() - 1) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

void BSTNode::printDFS() {
  
  std::vector<BSTNode*> order;
  dfs(order);
  
  std::cout << "{ ";
  for (int index = 0; index < order.size(); index++) {
    std::cout << order[index]->value;
    if (index < order.size() - 1) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

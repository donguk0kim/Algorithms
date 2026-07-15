#pragma once

#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>

#include "node.hpp"

std::list<Node*> tarjan(std::vector<Node*>& nodes);

bool visit(Node* node,
           std::unordered_set<Node*>& stack,
           std::unordered_set<Node*>& visited,
           std::list<Node*>& result
           );

void lprint(std::list<Node*>& list);

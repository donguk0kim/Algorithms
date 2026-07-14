#pragma once

#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>

#include "../Graphs/node.hpp"

std::list<Node*> Tarjan(std::vector<Node*>& nodes);

bool Visit(Node* node,
           std::unordered_set<Node*>& stack,
           std::unordered_set<Node*>& visited,
           std::list<Node*>& result
           );

void Lprint(std::list<Node*>& list);

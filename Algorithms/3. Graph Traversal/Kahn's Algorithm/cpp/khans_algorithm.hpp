#pragma once

#include <vector>

#include "../Graphs/node.hpp"

std::vector<Node*> Kahn(std::vector<Node*>& nodes);

void Vprint(std::vector<Node*>& array);

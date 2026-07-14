#pragma once

#include <vector>

#include "node.hpp"

std::vector<Node*> Kahn(std::vector<Node*>& nodes);

void Vprint(std::vector<Node*>& array);

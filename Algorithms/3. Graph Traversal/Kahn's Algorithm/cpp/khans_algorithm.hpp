#pragma once

#include <vector>

#include "node.hpp"

std::vector<Node*> kahn(std::vector<Node*>& nodes);

void vprint(std::vector<Node*>& array);

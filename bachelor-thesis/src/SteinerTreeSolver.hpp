#ifndef STEINER_TREE_SOLVER_KP
#define STEINER_TREE_SOLVER_KP

#include "BiDirGraph.hpp"
#include "SteinerTree.hpp"

class SteinerTreeSolver {
 public:
  SteinerTreeSolver(BiDirGraph graph, std::vector<int32_t> terminalNodes)
      : graph(graph), terminalNodes(terminalNodes){};

  virtual SteinerTree solve() = 0;

 private:
  BiDirGraph graph;
  std::vector<int32_t> terminalNodes;
};

#endif

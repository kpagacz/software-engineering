#ifndef STEINER_TREE_KP
#define STEINER_TREE_KP

#include "BiDirGraph.hpp"

class SteinerTree : public BiDirGraph {
 private:
  const std::unordered_set<int32_t> terminalNodes;
  std::unordered_set<int32_t> steinerNodes;

 public:
  SteinerTree(const BiDirGraph& graph, const std::unordered_set<int32_t>& terminalNodes)
      : BiDirGraph(graph), terminalNodes(terminalNodes) {}

  // TODO implement removing and adding nodes
  std::unordered_set<int32_t> getSteinerNodes() const { return steinerNodes; }
  std::unordered_set<int32_t> getTerminalNodes() const { return terminalNodes; }
};

#endif

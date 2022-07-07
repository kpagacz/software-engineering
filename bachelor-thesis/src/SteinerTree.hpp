#ifndef STEINER_TREE_KP
#define STEINER_TREE_KP

#include "BiDirGraph.hpp"

class SteinerTree : public BiDirGraph {
 private:
  std::unordered_set<int32_t> terminalNodes;

 public:
  SteinerTree(const BiDirGraph& graph, const std::unordered_set<int32_t>& terminalNodes)

      : BiDirGraph(graph), terminalNodes(terminalNodes) {}

  void removeNode(const int32_t& node) {
    terminalNodes.erase(node);
    BiDirGraph::removeNode(node);
  }

  std::unordered_set<int32_t> getTerminalNodes() const { return terminalNodes; }
};

#endif

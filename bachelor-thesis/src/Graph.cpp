#include "Graph.hpp"

BiDirGraph::BiDirGraph(const STPDocument& stpDocument) {
  for (const auto& edge : stpDocument.edges) addEdge(std::get<0>(edge), std::get<1>(edge), std::get<2>(edge));
}

void BiDirGraph::print() const { print(std::cout); }

void BiDirGraph::print(std::ostream& out) const {
  out << "BiDirGraph:\n";
  for (const auto& [node, edges] : adjacencyMap) {
    out << "  Node: " << node << " Edges: ";
    for (const auto& [destination, weight] : edges) out << "->" << destination << " (" << weight << ") ";
    out << '\n';
  }
}

std::unordered_set<int32_t> BiDirGraph::listNodes() const {
  std::unordered_set<int32_t> nodes;
  nodes.reserve(adjacencyMap.size());
  for (const auto& [node, ignored] : adjacencyMap) nodes.insert(node);
  return nodes;
}

BiDirGraph::ConstIterator BiDirGraph::putNode(const int32_t& node) {
  const auto& found = adjacencyMap.find(node);
  if (found != this->end()) return found;
  adjacencyMap.insert({node, {}});
  return adjacencyMap.find(node);
}

void BiDirGraph::removeNode(const int32_t& node) {
  adjacencyMap.erase(node);
  for (auto& [key, edges] : adjacencyMap) edges.erase(node);
}

void BiDirGraph::removeEdge(const int32_t& source, const int32_t& dest) {
  const auto& found = adjacencyMap.find(source);
  if (found != this->end()) found->second.erase(dest);

  const auto& foundDest = adjacencyMap.find(dest);
  if (foundDest != this->end()) foundDest->second.erase(source);
}

void BiDirGraph::addEdge(const int32_t& source, const int32_t& destination, const int32_t& weight) {
  putNode(source);
  putNode(destination);
  auto sourceNode = adjacencyMap.find(source);
  sourceNode->second.insert({destination, weight});
  auto destinationNode = adjacencyMap.find(destination);
  destinationNode->second.insert({source, weight});
}

BiDirGraph::ConstIterator BiDirGraph::getNode(const int32_t& node) const { return adjacencyMap.find(node); }
BiDirGraph::ConstIterator BiDirGraph::begin() const { return adjacencyMap.begin(); }
BiDirGraph::ConstIterator BiDirGraph::end() const { return adjacencyMap.end(); }

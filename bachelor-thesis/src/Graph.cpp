#include "Graph.hpp"

void Graph::print() const { print(std::cout); }

void Graph::print(std::ostream& out) const {
  out << "Graph:\n";
  for (const auto& [node, edges] : adjacencyMap) {
    out << "  Node: " << node << " Edges: ";
    std::copy(edges.begin(), edges.end(), std::ostream_iterator<int>(out, " "));
    out << '\n';
  }
}

std::vector<int32_t> Graph::listNodes() const {
  std::vector<int32_t> nodes;
  nodes.reserve(adjacencyMap.size());
  for (const auto& [node, ignored] : adjacencyMap) nodes.push_back(node);
  return nodes;
}

void Graph::removeNode(const int32_t& node) {
  adjacencyMap.erase(node);
  for (auto& [key, edges] : adjacencyMap) edges.erase(node);
}

void Graph::removeEdge(const int32_t& source, const int32_t& dest) {
  const auto& found = adjacencyMap.find(source);
  if (found != this->end()) found->second.erase(dest);

  const auto& foundDest = adjacencyMap.find(dest);
  if (foundDest != this->end()) foundDest->second.erase(source);
}

GraphConstIterator Graph::getNode(const int32_t& node) const { return adjacencyMap.find(node); }
GraphConstIterator Graph::begin() const { return adjacencyMap.begin(); }
GraphConstIterator Graph::end() const { return adjacencyMap.end(); }

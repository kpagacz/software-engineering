#ifndef GRAPH_KP
#define GRAPH_KP
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "./STPDocument.hpp"

class BiDirGraph {
 public:
  using Edges = std::unordered_map<int32_t, int32_t>;
  using AdjacencyMap = std::unordered_map<int32_t, BiDirGraph::Edges>;
  using ConstIterator = BiDirGraph::AdjacencyMap::const_iterator;
  BiDirGraph() = default;
  BiDirGraph(AdjacencyMap adjacencyMap) : adjacencyMap(adjacencyMap) {}
  BiDirGraph(const STPDocument& stdDocument);
  void print() const;
  void print(std::ostream& out) const;
  std::unordered_set<int> listNodes() const;

  ConstIterator putNode(const int32_t& node);

  void removeNode(const int32_t& node);
  void removeEdge(const int32_t& source, const int32_t& dest);
  void addEdge(const int32_t& source, const int32_t& destination, const int32_t& weight = 0);

  ConstIterator getNode(const int32_t& node) const;
  ConstIterator begin() const;
  ConstIterator end() const;

 private:
  AdjacencyMap adjacencyMap;
};

#endif

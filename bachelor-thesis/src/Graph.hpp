#ifndef GRAPH_KP
#define GRAPH_KP
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using AdjacencyMap = std::unordered_map<int32_t, std::unordered_set<int32_t>>;
using GraphConstIterator = std::unordered_map<int32_t, std::unordered_set<int32_t>>::const_iterator;

class Graph {
  AdjacencyMap adjacencyMap;

 public:
  Graph(AdjacencyMap adjacencyMap) : adjacencyMap(adjacencyMap) {}
  void print() const;
  void print(std::ostream& out) const;
  std::vector<int> listNodes() const;

  GraphConstIterator putNode(const int32_t& node);

  void removeNode(const int32_t& node);
  void removeEdge(const int32_t& source, const int32_t& dest);

  GraphConstIterator getNode(const int32_t& node) const;
  GraphConstIterator begin() const;
  GraphConstIterator end() const;
};

#endif

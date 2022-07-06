#ifndef GRAPH_KP
#define GRAPH_KP
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Graph {
 public:
  using Edges = std::unordered_map<int32_t, int32_t>;
  using AdjacencyMap = std::unordered_map<int32_t, Graph::Edges>;
  using ConstIterator = Graph::AdjacencyMap::const_iterator;
  Graph(AdjacencyMap adjacencyMap) : adjacencyMap(adjacencyMap) {}
  void print() const;
  void print(std::ostream& out) const;
  std::vector<int> listNodes() const;

  ConstIterator putNode(const int32_t& node);

  void removeNode(const int32_t& node);
  void removeEdge(const int32_t& source, const int32_t& dest);
  // TODO: implement addEdge
  void addEdge(const int32_t& source, const int32_t& destination, const int32_t& weight = 0);

  ConstIterator getNode(const int32_t& node) const;
  ConstIterator begin() const;
  ConstIterator end() const;

 private:
  AdjacencyMap adjacencyMap;
};

#endif

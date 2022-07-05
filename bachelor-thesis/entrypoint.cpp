#include "./src/Graph.hpp"

int main() {
  std::unordered_map<int, std::unordered_set<int>> adjacencyMap{{1, {2, 3}}, {2, {3}}, {3, {1}}};
  Graph* g = new Graph(adjacencyMap);
  g->print();

  const auto nodesList = g->listNodes();
  std::copy(nodesList.begin(), nodesList.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';
}

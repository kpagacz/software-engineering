#include <unordered_set>

#include "../../lib/doctest.h"
#include "../Graph.hpp"

TEST_CASE("Testing Graph") {
  Graph::AdjacencyMap adjacencyMap{{1, {{2, 0}, {3, 0}}}, {2, {{3, 0}}}, {3, {{1, 0}}}};
  Graph g(adjacencyMap);

  SUBCASE("removing a node from a vector") {
    g.removeNode(1);
    CHECK_EQ(std::vector<int>{3, 2}, g.listNodes());
    CHECK_NOTHROW(g.removeNode(1));
    CHECK_EQ(std::vector<int>{3, 2}, g.listNodes());
    CHECK_EQ(Graph::Edges{}, g.getNode(3)->second);
    g.removeNode(3);
    CHECK_EQ(std::vector<int>{2}, g.listNodes());
  }

  SUBCASE("getting a node") {
    const auto& node = g.getNode(3);
    CHECK_EQ(3, node->first);
    CHECK_EQ(Graph::Edges{{1, 0}}, node->second);

    const auto& node2 = g.getNode(4);
    CHECK_EQ(g.end(), node2);
  }

  SUBCASE("removing an edge") {
    const auto& node = g.getNode(3);
    CHECK_NOTHROW(g.removeEdge(3, 1));
    CHECK_EQ(Graph::Edges{}, node->second);
    CHECK_EQ(Graph::Edges{{2, 0}}, g.getNode(1)->second);
  }

  SUBCASE("removing an edge is idempotent") {
    CHECK_NOTHROW(g.removeEdge(3, 1));
    CHECK_EQ(Graph::Edges{}, g.getNode(3)->second);
    CHECK_EQ(Graph::Edges{{2, 0}}, g.getNode(1)->second);
    CHECK_NOTHROW(g.removeEdge(3, 1));
    CHECK_EQ(Graph::Edges{}, g.getNode(3)->second);
    CHECK_EQ(Graph::Edges{{2, 0}}, g.getNode(1)->second);
  }

  SUBCASE("putting a node adds a node") {
    CHECK_NOTHROW(g.putNode(4));
    std::vector<int> expectedNodes{1, 2, 3, 4};
    std::vector<int> difference;
    auto nodes = g.listNodes();
    std::sort(nodes.begin(), nodes.end());
    std::set_difference(expectedNodes.begin(), expectedNodes.end(), nodes.begin(), nodes.end(),
                        std::back_inserter(difference));
    CHECK(difference.size() == 0);
  }

  SUBCASE("putting a node is idempotent") {
    CHECK_NOTHROW(g.putNode(4));
    std::vector<int> expectedNodes{1, 2, 3, 4};
    std::vector<int> difference;
    auto nodes = g.listNodes();
    std::sort(nodes.begin(), nodes.end());
    std::set_difference(expectedNodes.begin(), expectedNodes.end(), nodes.begin(), nodes.end(),
                        std::back_inserter(difference));
    CHECK(difference.size() == 0);

    CHECK_NOTHROW(g.putNode(4));
    difference.clear();
    nodes = g.listNodes();
    std::sort(nodes.begin(), nodes.end());
    std::set_difference(expectedNodes.begin(), expectedNodes.end(), nodes.begin(), nodes.end(),
                        std::back_inserter(difference));
    CHECK(difference.size() == 0);
  }
}

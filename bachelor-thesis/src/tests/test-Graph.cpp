#include "../../lib/doctest.h"
#include "../Graph.hpp"

TEST_CASE("Testing Graph") {
  AdjacencyMap adjacencyMap{{1, {2, 3}}, {2, {3}}, {3, {1}}};
  Graph g(adjacencyMap);

  SUBCASE("removing a node from a vector") {
    g.removeNode(1);
    CHECK_EQ(std::vector<int>{3, 2}, g.listNodes());
    CHECK_NOTHROW(g.removeNode(1));
    CHECK_EQ(std::vector<int>{3, 2}, g.listNodes());
    CHECK_EQ(std::unordered_set<int32_t>{}, g.getNode(3)->second);
    g.removeNode(3);
    CHECK_EQ(std::vector<int>{2}, g.listNodes());
  }

  SUBCASE("getting a node") {
    const auto& node = g.getNode(3);
    CHECK_EQ(3, node->first);
    CHECK_EQ(std::unordered_set<int32_t>{1}, node->second);

    const auto& node2 = g.getNode(4);
    CHECK_EQ(g.end(), node2);
  }

  SUBCASE("removing an edge") {
    const auto& node = g.getNode(3);
    CHECK_NOTHROW(g.removeEdge(3, 1));
    CHECK_EQ(std::unordered_set<int32_t>{}, node->second);
    CHECK_EQ(std::unordered_set<int32_t>{2}, g.getNode(1)->second);
  }

  SUBCASE("removing an edge is idempotent") {
    CHECK_NOTHROW(g.removeEdge(3, 1));
    CHECK_EQ(std::unordered_set<int32_t>{}, g.getNode(3)->second);
    CHECK_EQ(std::unordered_set<int32_t>{2}, g.getNode(1)->second);
    CHECK_NOTHROW(g.removeEdge(3, 1));
    CHECK_EQ(std::unordered_set<int32_t>{}, g.getNode(3)->second);
    CHECK_EQ(std::unordered_set<int32_t>{2}, g.getNode(1)->second);
  }
}

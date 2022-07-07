#include <unordered_set>

#include "../../lib/doctest.h"
#include "../BiDirGraph.hpp"
#include "../STPDocument.hpp"

TEST_CASE("Testing BiDirGraph") {
  BiDirGraph::AdjacencyMap adjacencyMap{{1, {{2, 0}, {3, 0}}}, {2, {{1, 0}}}, {3, {{1, 0}}}};
  BiDirGraph g(adjacencyMap);

  SUBCASE("removing a node from a vector") {
    g.removeNode(1);
    CHECK_EQ(std::unordered_set<int>{3, 2}, g.listNodes());
    CHECK_NOTHROW(g.removeNode(1));
    CHECK_EQ(std::unordered_set<int>{3, 2}, g.listNodes());
    CHECK_EQ(BiDirGraph::Edges{}, g.getNode(3)->second);
    g.removeNode(3);
    CHECK_EQ(std::unordered_set<int>{2}, g.listNodes());
  }

  SUBCASE("getting a node") {
    const auto& node = g.getNode(3);
    CHECK_EQ(3, node->first);
    CHECK_EQ(BiDirGraph::Edges{{1, 0}}, node->second);

    const auto& node2 = g.getNode(4);
    CHECK_EQ(g.end(), node2);
  }

  SUBCASE("removing an edge") {
    const auto& node = g.getNode(3);
    CHECK_NOTHROW(g.removeEdge(3, 1));
    CHECK_EQ(BiDirGraph::Edges{}, node->second);
    CHECK_EQ(BiDirGraph::Edges{{2, 0}}, g.getNode(1)->second);
  }

  SUBCASE("removing an edge is idempotent") {
    CHECK_NOTHROW(g.removeEdge(3, 1));
    CHECK_EQ(BiDirGraph::Edges{}, g.getNode(3)->second);
    CHECK_EQ(BiDirGraph::Edges{{2, 0}}, g.getNode(1)->second);
    CHECK_NOTHROW(g.removeEdge(3, 1));
    CHECK_EQ(BiDirGraph::Edges{}, g.getNode(3)->second);
    CHECK_EQ(BiDirGraph::Edges{{2, 0}}, g.getNode(1)->second);
  }

  SUBCASE("putting a node adds a node") {
    CHECK_NOTHROW(g.putNode(4));
    std::unordered_set<int> expectedNodes{1, 2, 3, 4};
    CHECK_EQ(expectedNodes, g.listNodes());
  }

  SUBCASE("putting a node is idempotent") {
    CHECK_NOTHROW(g.putNode(4));
    std::unordered_set<int> expectedNodes{1, 2, 3, 4};
    CHECK_EQ(expectedNodes, g.listNodes());

    CHECK_NOTHROW(g.putNode(4));
    CHECK_EQ(expectedNodes, g.listNodes());
  }

  SUBCASE("adding an edge inserts missing nodes") {
    auto nodesBeforeEdgeInsertion = g.listNodes();
    g.addEdge(4, 5, 0);
    nodesBeforeEdgeInsertion.insert(4);
    nodesBeforeEdgeInsertion.insert(5);
    CHECK_EQ(nodesBeforeEdgeInsertion, g.listNodes());
  }

  SUBCASE("an added edge has the default weight of 0") {
    g.addEdge(2, 3);
    auto node2 = g.getNode(2);
    CHECK_EQ(node2->second.find(3)->second, 0);
  }
}

TEST_CASE("BiDirGraph can be constructed from STPDocument") {
  STPDocument* document = new STPDocument();
  REQUIRE(document != nullptr);
  std::vector<STPDocument::edgeType> edges;
  edges.push_back({1, 2, 5});
  edges.push_back({2, 3, 6});
  document->edges = edges;

  BiDirGraph* graph;
  CHECK_NOTHROW(graph = new BiDirGraph(*document));

  SUBCASE("BiDirGraph constructed from STPDocument has correct nodes") {
    CHECK_EQ(std::unordered_set<int32_t>{1, 2, 3}, graph->listNodes());
  }
}

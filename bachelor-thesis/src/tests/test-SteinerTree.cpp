#include "../../lib/doctest.h"
#include "../SteinerTree.hpp"

TEST_CASE("Testing SteinerTree") {
  BiDirGraph::AdjacencyMap adjacencyMap{{1, {{2, 0}, {3, 0}}}, {2, {{1, 0}}}, {3, {{1, 0}}}};
  BiDirGraph g(adjacencyMap);
  std::unordered_set<int32_t> terminalNodes{1, 2, 3};
  SteinerTree* st = new SteinerTree(g, terminalNodes);
  REQUIRE(st != nullptr);
  CHECK_EQ(std::unordered_set<int32_t>{1, 2, 3}, st->listNodes());
  CHECK_EQ(std::unordered_set<int32_t>{1, 2, 3}, st->getTerminalNodes());
  CHECK_NOTHROW(st->removeNode(1));
  CHECK_EQ(std::unordered_set<int>{2, 3}, st->listNodes());
  CHECK_EQ(std::unordered_set<int32_t>{2, 3}, st->getTerminalNodes());
  CHECK_NOTHROW(st->removeNode(2));
  CHECK_EQ(std::unordered_set<int32_t>{3}, st->listNodes());
  CHECK_EQ(std::unordered_set<int32_t>{3}, st->getTerminalNodes());
  CHECK_NOTHROW(st->removeNode(3));
  CHECK_EQ(std::unordered_set<int32_t>{}, st->listNodes());
  CHECK_EQ(std::unordered_set<int32_t>{}, st->getTerminalNodes());
}

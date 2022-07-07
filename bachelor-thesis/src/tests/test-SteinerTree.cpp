#include "../../lib/doctest.h"
#include "../SteinerTree.hpp"

TEST_CASE("Testing SteinerTree") {
  BiDirGraph::AdjacencyMap adjacencyMap{{1, {{2, 0}, {3, 0}}}, {2, {{1, 0}}}, {3, {{1, 0}}}};
  BiDirGraph g(adjacencyMap);
  std::unordered_set<int32_t> terminalNodes{1, 2, 3};
  SteinerTree st(g, terminalNodes);
  CHECK_EQ(std::unordered_set<int>{1, 2, 3}, st.listNodes());
  CHECK_EQ(std::unordered_set<int>{1, 2, 3}, st.getTerminalNodes());
  CHECK_EQ(std::unordered_set<int32_t>{}, st.getSteinerNodes());
  CHECK_NOTHROW(st.removeNode(1));
  CHECK_EQ(std::unordered_set<int>{2, 3}, st.listNodes());
  CHECK_EQ(std::unordered_set<int>{2, 3}, st.getTerminalNodes());
  CHECK_EQ(std::unordered_set<int32_t>{}, st.getSteinerNodes());
  CHECK_NOTHROW(st.removeNode(2));
  CHECK_EQ(std::unordered_set<int>{3}, st.listNodes());
  CHECK_EQ(std::unordered_set<int>{3}, st.getTerminalNodes());
  CHECK_EQ(std::unordered_set<int32_t>{}, st.getSteinerNodes());
  CHECK_NOTHROW(st.removeNode(3));
  CHECK_EQ(std::unordered_set<int>{}, st.listNodes());
  CHECK_EQ(std::unordered_set<int>{}, st.getTerminalNodes());
  CHECK_EQ(std::unordered_set<int32_t>{}, st.getSteinerNodes());
}

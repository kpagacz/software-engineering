#include "./STPInputReader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "./STPDocument.hpp"

STPDocument* STPInputReader::read() const {
  std::ifstream inFile(path);
  if (!inFile) return nullptr;

  STPDocument* document = new STPDocument();

  std::string line;

  while (std::getline(inFile, line)) {
    if (line == "SECTION Graph") {
      int nodesCount;
      std::vector<STPDocument::edgeType> edges;
      std::getline(inFile, line);
      std::sscanf(line.c_str(), "Nodes %d", &nodesCount);
      std::getline(inFile, line);
      int edgesCount;
      std::sscanf(line.c_str(), "Edges %d", &edgesCount);
      for (int i = 0; i < edgesCount; ++i) {
        std::getline(inFile, line);
        STPDocument::edgeType edge{-1, -1, -1};
        std::sscanf(line.c_str(), "E %d %d %d", &std::get<0>(edge), &std::get<1>(edge), &std::get<2>(edge));
        edges.push_back(edge);
      }
      document->edges = std::move(edges);
      document->nodesCount = std::move(nodesCount);
    }

    if (line == "SECTION Terminals") {
      std::getline(inFile, line);
      int terminalsCount;
      std::sscanf(line.c_str(), "Terminals %d", &terminalsCount);
      std::vector<int32_t> terminals(terminalsCount);
      for (int i = 0; i < terminalsCount; ++i) {
        std::getline(inFile, line);
        std::sscanf(line.c_str(), "T %d", &terminals[i]);
      }
      document->terminalNodes = std::move(terminals);
    }
  }

  return document;
}

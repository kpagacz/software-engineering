#ifndef STP_DOCUMENT_KP
#define STP_DOCUMENT_KP

#include <tuple>
#include <vector>

class STPDocument {
 public:
  int nodesCount;
  std::vector<std::tuple<int32_t, int32_t, int32_t>> edges;
  std::vector<int32_t> terminalNodes;
  using edgeType = std::tuple<int32_t, int32_t, int32_t>;
  STPDocument() = default;
};

#endif

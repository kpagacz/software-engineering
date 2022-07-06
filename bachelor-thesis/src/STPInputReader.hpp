#ifndef STP_INPUT_READER_KP
#define STP_INPUT_READER_KP

#include <string>

#include "./STPDocument.hpp"

class STPInputReader {
 public:
  STPInputReader(std::string path) : path(path){};
  STPDocument* read() const;

 private:
  std::string path;
};

#endif

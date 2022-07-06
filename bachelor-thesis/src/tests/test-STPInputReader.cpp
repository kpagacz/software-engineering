#include "../../lib/doctest.h"
#include "../STPInputReader.hpp"

TEST_CASE("STPInputReader constructor does not throw") {
  std::string testFile{"./src/tests/test-stp-files/test0.stp"};
  CHECK_NOTHROW(new STPInputReader(testFile));
}

TEST_CASE("STPInputReader reads an .stp file") {
  std::string testFile{"./src/tests/test-stp-files/test0.stp"};
  STPInputReader* reader;
  REQUIRE_NOTHROW(reader = new STPInputReader(testFile));
  REQUIRE(reader != nullptr);

  SUBCASE("read returns an STPDocument object") {
    STPDocument* document = reader->read();
    CHECK(document != nullptr);
  }
}

SCENARIO("STPInputReader integration test with STPDocument") {
  GIVEN("STPInputReader from an .stp file") {
    std::string testFile{"./src/tests/test-stp-files/test0.stp"};
    STPInputReader reader(testFile);

    WHEN("the reader returns STPDocument") {
      STPDocument* document = reader.read();

      THEN("the document's nodes count matches the .stp file") { CHECK_EQ(50, document->nodesCount); }
      AND_THEN("the document's edges size matches the .stp file") { CHECK_EQ(std::size_t{63}, document->edges.size()); }
      AND_THEN("the document's terminals size matches the .stp file") {
        CHECK_EQ(std::size_t{9}, document->terminalNodes.size());
      }
    }
  }
}

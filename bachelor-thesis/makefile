CXX := g++
IDIR := ./src
CXXFLAGS := -I$(IDIR) -std=c++2a
DEPS_ := Graph.hpp STPInputReader.hpp STPDocument.hpp
DEPS := $(DEPS_:%=$(IDIR)/%)
OBJ_ := Graph.o STPInputReader.o STPDocument.o
OBJ := $(OBJ_:%=$(IDIR)/%)

graph: $(OBJ)
	$(CXX) $(STD) -o $@ $^ entrypoint.o $(CXXFLAGS)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

TESTDIR := $(IDIR)/tests
TESTS_ := test.o test-Graph.o test-STPInputReader.o
TESTS := $(TESTS_:%=$(TESTDIR)/%)
test: $(DEPS) $(OBJ) $(TESTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@

clean:
	rm -f $(OBJ) test graph $(TESTS) entrypoint.o

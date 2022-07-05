CXX := g++
IDIR := ./src
CXXFLAGS := -I$(IDIR) -std=c++2a
DEPS_ := Graph.hpp
DEPS := $(DEPS_:%=$(IDIR)/%)
OBJ_ := Graph.o
OBJ := $(OBJ_:%=$(IDIR)/%)

graph: $(OBJ)
	$(CXX) $(STD) -o $@ $^ entrypoint.o $(CXXFLAGS)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

TESTDIR := $(IDIR)/tests
TESTS_ := test.o test-Graph.o
TESTS := $(TESTS_:%=$(TESTDIR)/%)
test: $(DEPS) $(OBJ) $(TESTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@

clean:
	rm -f $(OBJ) test graph $(TESTS) entrypoint.o

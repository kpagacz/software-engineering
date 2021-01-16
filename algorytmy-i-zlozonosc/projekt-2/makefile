CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall
BIN=project2

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $^

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f *.o
	rm $(BIN)

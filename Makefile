CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

all: bin/testListArray

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testListArray testListArray.cpp

clean:
	rm -rf bin *.o *.gch


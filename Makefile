CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Regla por defecto
all: bin/testListArray bin/testNode bin/testListLinked bin/testPoint2D bin/testCircle bin/testRectangle bin/testSquare bin/testDrawing

# Reglas para los binarios de prueba
bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testListArray testListArray.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testNode testNode.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testListLinked testListLinked.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.cpp Point2D.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testPoint2D testPoint2D.cpp Point2D.cpp

bin/testCircle: testCircle.cpp Circle.cpp Circle.h Shape.cpp Shape.h Point2D.cpp Point2D.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testCircle testCircle.cpp Circle.cpp Shape.cpp Point2D.cpp

bin/testRectangle: testRectangle.cpp Rectangle.cpp Rectangle.h Shape.cpp Shape.h Point2D.cpp Point2D.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testRectangle testRectangle.cpp Rectangle.cpp Shape.cpp Point2D.cpp

bin/testSquare: testSquare.cpp Square.cpp Square.h Rectangle.cpp Rectangle.h Shape.cpp Shape.h Point2D.cpp Point2D.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testSquare testSquare.cpp Square.cpp Rectangle.cpp Shape.cpp Point2D.cpp

bin/testDrawing: testDrawing.cpp Drawing.cpp Drawing.h Circle.cpp Circle.h Square.cpp Square.h Rectangle.cpp Rectangle.h Shape.cpp Shape.h Point2D.cpp Point2D.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testDrawing testDrawing.cpp Drawing.cpp Circle.cpp Square.cpp Rectangle.cpp Shape.cpp Point2D.cpp

# Regla para limpiar
clean:
	rm -rf bin *.o *.gch


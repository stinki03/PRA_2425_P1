#include "Drawing.h"
#include "Circle.h"
#include "Square.h"

Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {
        std::cout << *(shapes->get(i)) << std::endl;
    }
}

double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* shape = shapes->get(i);
        Circle* circle = dynamic_cast<Circle*>(shape);
        if (circle) {
            total_area += circle->area();
        }
    }
    return total_area;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Shape* shape = shapes->get(i);
        Square* square = dynamic_cast<Square*>(shape);
        if (square) {
            square->translate(incX, incY);
        }
    }
}


#include "Square.h"

Square::Square() : Rectangle() {}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for square");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for square");
    }
    Rectangle::set_vertices(vertices);
}

void Square::print() const {
    std::cout << "[Square: color = " << get_color() << "; vertices = (";
    for (int i = 0; i < N_VERTICES; ++i) {
        std::cout << vs[i];
        if (i < N_VERTICES - 1) {
            std::cout << ", ";
        }
    }
    std::cout << ")]";
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
    square.print();
    return out;
}

bool Square::check(Point2D* vertices) {
    double a = Point2D::distance(vertices[0], vertices[1]);
    double b = Point2D::distance(vertices[1], vertices[2]);
    double c = Point2D::distance(vertices[2], vertices[3]);
    double d = Point2D::distance(vertices[3], vertices[0]);
    return a == b && b == c && c == d;
}


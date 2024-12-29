#include "Rectangle.h"

Rectangle::Rectangle() : Shape(), vs(new Point2D[N_VERTICES]) {
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color), vs(new Point2D[N_VERTICES]) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for rectangle");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.get_color()), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid vertices for rectangle");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

double Rectangle::area() const {
    double a = Point2D::distance(vs[0], vs[1]);
    double b = Point2D::distance(vs[1], vs[2]);
    return a * b;
}

double Rectangle::perimeter() const {
    double a = Point2D::distance(vs[0], vs[1]);
    double b = Point2D::distance(vs[1], vs[2]);
    return 2 * (a + b);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() const {
    std::cout << "[Rectangle: color = " << get_color() << "; vertices = (";
    for (int i = 0; i < N_VERTICES; ++i) {
        std::cout << vs[i];
        if (i < N_VERTICES - 1) {
            std::cout << ", ";
        }
    }
    std::cout << ")]";
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    r.print();
    return out;
}

bool Rectangle::check(Point2D* vertices) {
    double a = Point2D::distance(vertices[0], vertices[1]);
    double b = Point2D::distance(vertices[1], vertices[2]);
    double c = Point2D::distance(vertices[2], vertices[3]);
    double d = Point2D::distance(vertices[3], vertices[0]);
    return a == c && b == d;
}


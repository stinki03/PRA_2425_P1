#include "Point2D.h"

Point2D::Point2D(double x, double y) : x(x), y(y) {}

double Point2D::distance(const Point2D &a, const Point2D &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool Point2D::operator==(const Point2D &a) const {
    return x == a.x && y == a.y;
}

bool Point2D::operator!=(const Point2D &a) const {
    return !(*this == a);
}

std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}


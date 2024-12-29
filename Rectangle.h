#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point2D.h"
#include <iostream>

class Rectangle : public Shape {
protected:
    Point2D* vs;
    static const int N_VERTICES = 4;

public:
    Rectangle();
    Rectangle(std::string color, Point2D* vertices);
    Rectangle(const Rectangle &r);
    virtual void set_vertices(Point2D* vertices);  // Asegúrate de que esté marcado como virtual
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    virtual void print() const override;  // Asegúrate de que esté marcado como virtual
    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

private:
    static bool check(Point2D* vertices);
};

#endif


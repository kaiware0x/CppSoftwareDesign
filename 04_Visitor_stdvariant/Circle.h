#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle {
public:
    explicit Circle(double radius) : m_radius(radius) {}

    auto radius() const { return m_radius; }
    auto center() const { return m_center; }

private:
    double m_radius;
    Point  m_center;
};

#endif    // CIRCLE_H

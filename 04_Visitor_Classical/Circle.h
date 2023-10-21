#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
   public:
    explicit Circle(const double& radius) : Shape(), m_radius(radius) {}

    void accept(const ShapeVisitor& visitor) override {
        std::cout << "Accept Circle\n";
        visitor.visit(*this);
    }

    auto radius() const { return m_radius; }

   private:
    double m_radius;
};

#endif
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "ShapeVisitor.h"

class Square : public Shape {
   public:
    explicit Square(const double& side) : Shape(), m_side(side) {}

    void accept(const ShapeVisitor& visitor) override {
        std::cout << "Accept Square\n";
        visitor.visit(*this);
    }

    auto side() const { return m_side; }

   private:
    double m_side;
};

#endif
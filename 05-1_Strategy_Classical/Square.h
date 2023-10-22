#ifndef SQUARE_H
#define SQUARE_H

#include <memory>

#include "DrawStrategy.h"
#include "Shape.h"

/// @brief アーキテクチャ中位：Strategyと抽象Shapeに依存している
class Square : public Shape {
   public:
    explicit Square(const double& side,
                    std::unique_ptr<DrawStrategy<Square>> drawer)
        : Shape(), m_side(side), m_drawer(std::move(drawer)) {}

    void draw() const override { m_drawer->draw(*this); }

   private:
    double m_side;

    std::unique_ptr<DrawStrategy<Square>> m_drawer;
};

#endif

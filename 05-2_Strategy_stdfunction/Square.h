#ifndef SQUARE_H
#define SQUARE_H

#include <functional>
#include <memory>
#include <utility>

#include "Shape.h"

/// @brief アーキテクチャ中位：Strategyと抽象Shapeに依存している
class Square : public Shape {
   public:
    using DrawStrategy = std::function<void(const Square&)>;

    explicit Square(const double& side, DrawStrategy drawer)
        : Shape(), m_side(side), m_drawer(std::move(drawer)) {}

    void draw() const override { m_drawer(*this); }

   private:
    double m_side;

    DrawStrategy m_drawer;
};

#endif

#ifndef OPENGL_CIRCLE_STRATEGY_H
#define OPENGL_CIRCLE_STRATEGY_H

#include <iostream>

#include "Circle.h"
#include "DrawStrategy.h"

/// @brief アーキテクチャ下位：Strategyと具象Shapeに依存している
class OpenGLCircleStrategy : public DrawStrategy<Circle> {
   public:
    void draw(const Circle& circle) const override {
        std::cout << "Draw circle\n";
    }
};

#endif

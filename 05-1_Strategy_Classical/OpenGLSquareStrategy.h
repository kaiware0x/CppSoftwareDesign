#ifndef OPENGL_SQUARE_STRATEGY_H
#define OPENGL_SQUARE_STRATEGY_H

#include <iostream>

#include "DrawStrategy.h"
#include "Square.h"

/// @brief アーキテクチャ下位：Strategyと具象Shapeに依存している
class OpenGLSquareStrategy : public DrawStrategy<Square> {
   public:
    void draw(const Square& square) const override {
        std::cout << "Draw square\n";
    }
};

#endif

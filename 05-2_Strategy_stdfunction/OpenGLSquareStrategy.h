#ifndef OPENGL_SQUARE_STRATEGY_H
#define OPENGL_SQUARE_STRATEGY_H

#include <iostream>

#include "Square.h"

/// @brief アーキテクチャ下位：具象Shapeのみに依存している
class OpenGLSquareStrategy {
   public:
    explicit OpenGLSquareStrategy(/*描画に必要な引数を渡す*/) {}

    void operator()(const Square& square) const {
        std::cout << "Draw square\n";
    }

   private:
    /* 描画に必要な値 */
};

#endif

#ifndef OPENGL_DRAW_STRATEGY_H
#define OPENGL_DRAW_STRATEGY_H

#include <iostream>

#include "Circle.h"
#include "Square.h"

/**
 * 描画処理の具体的な実装を行う。
 */
class OpenGLDrawStrategy {
   public:
    explicit OpenGLDrawStrategy(/*描画に必要な引数を渡す*/) {}

    void operator()(const Circle& circle) const {
        std::cout << "Draw circle\n";
    }
    void operator()(const Square& square) const {
        std::cout << "Draw square\n";
    }

   private:
    /* 描画に必要な値 */
};

#endif

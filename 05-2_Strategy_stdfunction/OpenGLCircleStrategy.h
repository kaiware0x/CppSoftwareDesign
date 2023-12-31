﻿#ifndef OPENGL_CIRCLE_STRATEGY_H
#define OPENGL_CIRCLE_STRATEGY_H

#include <iostream>

#include "Circle.h"

/// @brief アーキテクチャ下位：具象Shapeのみに依存している
class OpenGLCircleStrategy {
   public:
    explicit OpenGLCircleStrategy() {}

    void operator()(const Circle& circle) const {
        std::cout << "Draw circle\n";
    }

   private:
    /* 描画に必要な値 */
};

#endif

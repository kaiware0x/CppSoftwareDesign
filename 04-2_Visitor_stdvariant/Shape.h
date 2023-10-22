#ifndef SHAPE_H
#define SHAPE_H

#include <variant>
#include "Circle.h"
#include "Square.h"

/// 基底クラスの代わりに std::variant を使う
using Shape = std::variant<Circle, Square>;

#endif    // SHAPES_H

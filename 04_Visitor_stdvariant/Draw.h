#ifndef DRAW_H
#define DRAW_H

#include <iostream>
#include "Shape.h"

struct Draw {
    void operator()(const Circle& circle) const { std::cout << "Draw circle\n"; }
    void operator()(const Square& square) const { std::cout << "Draw square\n"; }
};

#endif    // DRAW_H


#include <iostream>
#include <vector>

#include "Circle.h"
#include "OpenGLCircleStrategy.h"
#include "OpenGLSquareStrategy.h"
#include "Square.h"

int main(int argc, char const* argv[]) {
    using Shapes = std::vector<std::unique_ptr<Shape>>;

    Shapes shapes{};

    shapes.emplace_back(std::make_unique<Circle>(
        2.3, std::make_unique<OpenGLCircleStrategy>()));

    shapes.emplace_back(std::make_unique<Square>(
        1.2, std::make_unique<OpenGLSquareStrategy>()));

    shapes.emplace_back(std::make_unique<Circle>(
        4.1, std::make_unique<OpenGLCircleStrategy>()));

    for (auto&& shape : shapes) {
        shape->draw();
    }

    return 0;
}

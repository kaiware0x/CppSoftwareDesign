
#include <iostream>
#include <memory>
#include <vector>

void draw(int i) { std::cout << "Draw int free\n"; }

#include "Circle.h"
#include "OpenGLDrawStrategy.h"
#include "Shape.h"
#include "Square.h"

int main(int argc, char const* argv[]) {
    using Shapes = std::vector<std::unique_ptr<ShapeConcept>>;

    using CircleModel = ShapeModel<Circle, OpenGLDrawStrategy>;
    using SquareModel = ShapeModel<Square, OpenGLDrawStrategy>;

    Shapes shapes{};

    shapes.emplace_back(
        std::make_unique<CircleModel>(Circle{2.3}, OpenGLDrawStrategy{}));
    shapes.emplace_back(
        std::make_unique<SquareModel>(Square{1.2}, OpenGLDrawStrategy{}));
    shapes.emplace_back(
        std::make_unique<CircleModel>(Circle{4.1}, OpenGLDrawStrategy{}));

    for (auto&& shape : shapes) {
        shape->draw();
    }

    using IntModel = ShapeModel<int>;
    auto shape = std::make_unique<IntModel>(int{42});
    shape->draw();

    return 0;
}

/**
 * CircleやSquareは仮想関数を一切持たないが、
 * External Polymorphismによって多態的に扱える。
 */

#include <memory>
#include <vector>

#include "Circle.h"
#include "DrawAllShapes.h"
#include "Shape.h"
#include "Square.h"

int main(int argc, char const *argv[]) {
    using Shapes = std::vector<std::unique_ptr<Shape>>;

    Shapes shapes;

    shapes.emplace_back(std::make_unique<Circle>(2.3));
    shapes.emplace_back(std::make_unique<Square>(1.2));
    shapes.emplace_back(std::make_unique<Circle>(4.1));

    drawAllShapes(shapes);

    return 0;
}

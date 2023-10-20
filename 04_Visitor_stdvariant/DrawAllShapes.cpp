
#include "DrawAllShapes.h"
#include "Draw.h"

void drawAllShapes(const Shapes& shapes)
{
    std::cout << "Draw with std::visit()\n";

    /// GCC: 1.1992s
    /// clang: 1.2279s
    for (auto&& shape : shapes) {
        std::visit(Draw{}, shape);

        /// 古典的実装では仮想関数の呼び出しが2回発生する
        /// virtual function table (vtbl)
        //        visitor->visit(shape);
        //        shape.accept(visitor);
    }

    std::cout << "Draw with std::get_if()\n";

    /// GCC: 1.0252s
    /// clang: 0.6998s
    for (auto&& shape : shapes) {
        if (const Circle* circle = std::get_if<Circle>(&shape)) {
            Draw{}(*circle);
        }
        else if (const Square* square = std::get_if<Square>(&shape)) {
            Draw{}(*square);
        }
    }
}

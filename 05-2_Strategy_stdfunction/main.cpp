
#include <iostream>
#include <vector>

#include "Circle.h"
#include "OpenGLCircleStrategy.h"
#include "OpenGLSquareStrategy.h"
#include "Square.h"

int main(int argc, char const* argv[])
{
    using Shapes = std::vector<std::unique_ptr<Shape>>;

    Shapes shapes{};

    shapes.emplace_back(std::make_unique<Circle>(2.3, OpenGLCircleStrategy{}));
    shapes.emplace_back(std::make_unique<Square>(1.2, OpenGLSquareStrategy{}));
    shapes.emplace_back(std::make_unique<Circle>(4.1, OpenGLCircleStrategy{}));

    for (auto&& shape : shapes) {
        shape->draw();
    }

    return 0;
}

/**
Strategyオブジェクトを関数オブジェクトとして実装。

Pros:
- Strategyオブジェクトのライフタイムを気にしなくて良くなる
- クラス間を疎結合にできる

Cons:
- std::functionに置き換えられるのは1つの仮想関数のみ
    - 置き換えたい仮想関数の個数分、引数で関数オブジェクトを渡す必要がある
*/

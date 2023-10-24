
#include <iostream>
#include <memory>
#include <vector>

void draw(int i)
{
    std::cout << "Draw int free\n";
}

#include "Circle.h"
// #include "OpenGLDrawStrategy.h"
#include "Shape.h"

int main(int argc, char const* argv[])
{
    // 具象図形クラスの生成
    Circle circle{3.14};

    // Draw Strategyの生成
    auto drawer = [](const Circle& c) { std::cout << "Draw circle, radius=" << c.radius() << std::endl; };

    // 具象図形と描画Strategyを組み合わせる。
    // コンストラクタでShapeModelがインスタンス化される。
    Shape shape1(circle, drawer);

    // 以前作成した関数オブジェクトを与えても良い
    // Shape shape1(circle, OpenGLDrawStrategy{});

    // 描画
    draw(shape1);

    // コピーコンストラクト
    Shape shape2(shape1);

    // shape1と同じ結果を返すはず
    draw(shape2);

    std::cout << "is equal: " << (shape1 == shape2) << std::endl;

    return 0;
}

/**
 * CircleやSquareは仮想関数を一切持たないが、
 * External Polymorphismによって多態的に扱える。
 *
 * main()の中でもはやポインタは存在しない。
 * 更に継承階層を扱う必要もない。
 */

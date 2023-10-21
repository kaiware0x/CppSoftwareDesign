#include <any>
#include <iostream>

#include "Circle.h"
#include "DrawAllShapes.h"
#include "Shapes.h"
#include "Square.h"

/// 参考:
/// https://www.oreilly.co.jp/books/9784814400454/

struct Print {
    Print() { std::cout << __func__ << std::endl; }
    void operator()(const int &value) const {
        std::cout << "int: " << value << '\n';
    }
    void operator()(const double &value) const {
        std::cout << "double: " << value << '\n';
    }
    void operator()(const std::string &value) const {
        std::cout << "string: " << value << '\n';
    }
};

int main() {
    ///---------------------------------------------------------------------------------------------------
    /// std::variantの基礎
    ///---------------------------------------------------------------------------------------------------

    /// int, double, string のどれかの値を持つ.
    std::variant<int, double, std::string> var{};

    std::variant<float, double> var1{};
    var1 = 1.0;
    var1 = 1.0f;

    /// int, double, string を代入できる.
    /// ただし最後に代入された値のみ有効.
    var = 42;
    var = 3.14;
    var = 2.71f;
    var = "Hello";

    /// int型の値を取得.
    /// varに格納されている値がint以外の場合は例外が飛ぶ.
    try {
        const int i = std::get<int>(var);
        std::cout << "var contains int: " << i << '\n';
    } catch (std::bad_variant_access e) {
        std::cout << e.what() << '\n';
    }

    /// int型の値のポインタを取得.
    /// varに格納されている値がint以外の場合はnullptrになる.
    if (const int *i_ptr = std::get_if<int>(&var)) {
        std::cout << "var contains int: " << *i_ptr << '\n';
    } else {
        std::cout << "var does not contains int" << '\n';
    }

    /// varに現在格納されている値から適切なoperator()が呼ばれる.
    std::visit(Print{}, var);

    /// C言語の共用体(Union)
    /// C++ではstd::variantが上位互換なので非推奨.
    /// 組み込みではサイズが不定なstd::variantは非推奨？
    union U {
        int i;
        double d;
    };
    union U u = {1};
    u.d = 2.4;
    std::cout << u.i << '\n';
    std::cout << u.d << '\n';

    ///---------------------------------------------------------------------------------------------------
    /// std::variantを用いたVisitorパターンの実装
    ///---------------------------------------------------------------------------------------------------

    Shapes shapes;

    shapes.emplace_back(Circle{2.3});
    shapes.emplace_back(Square{1.2});
    shapes.emplace_back(Circle{4.1});

    drawAllShapes(shapes);

    return 0;
}

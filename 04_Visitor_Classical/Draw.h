#ifndef DRAW_H
#define DRAW_H

#include "ShapeVisitor.h"

/// @brief 描画処理を実装する
/// Pros:
/// 回転処理を実装したい場合、ShapeVisitorを継承したRotateクラスを作れば良い
class Draw : public ShapeVisitor {
   public:
    void visit(const Circle& circle) const override {
        std::cout << "Visit circle\n";
    }
    void visit(const Square& square) const override {
        std::cout << "Visit square\n";
    }
};

#endif
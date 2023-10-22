#ifndef SHAPE_VISITOR_H
#define SHAPE_VISITOR_H

#include <iostream>

class Circle;
class Square;

/// @brief Shapeに対して拡張処理を提供する
/// Pros: 処理をVisitorクラスとして実装することで図形の基底クラス Shape
/// を変更せずに処理を追加できる。
/// → 処理に対するオープンセットになっていると言える。
///
/// Cons: 新しいVisitorを追加すると、
/// すべての図形クラスに対するvisit() を実装する必要がある。
/// (それぞれのvisit()の処理内容がほぼ同じだとしても)
/// → 型に対するクローズセットになっていると言える。
///
/// Cons: visit()は戻り値を返せない。
/// 処理結果はVisitorのメンバ変数に置く必要がある。
class ShapeVisitor {
   public:
    virtual ~ShapeVisitor() = default;

    virtual void visit(const Circle&) const = 0;
    virtual void visit(const Square&) const = 0;
};

#endif
#ifndef SHAPE_H
#define SHAPE_H

#include "ShapeVisitor.h"

/// @brief すべての図形の基底クラス。
class Shape {
   public:
    virtual ~Shape() = default;

    /// @brief Visitorが持つ処理内容を受け入れる。
    /// @param visitor
    virtual void accept(const ShapeVisitor& visitor) = 0;

    /// Cons: 別のVisitor基底クラスに対応する場合、
    /// 基底クラスShapeに別のaccept()=0を宣言する必要がある。
    /// これにより、Shapeを継承するクラスすべてが新しいaccept()を
    /// 再実装する必要がでてきてしまう。
};

#endif
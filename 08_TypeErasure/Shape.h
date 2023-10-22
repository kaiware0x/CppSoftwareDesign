#ifndef SHAPE_H
#define SHAPE_H

#include "Detail.h"

/**
 * ラッパークラス
 */
class Shape {
   public:
    /**
     * コンストラクタを抜けると、ShapeクラスはShapeTやDrawStrategyについて忘れる
     * →Type Erasure
     * m_pimplにすべて隠蔽される
     */
    template <class ShapeT, class DrawStrategy>
    Shape(ShapeT shape, DrawStrategy drawer) {
        using Model = detail::OwningShapeModel<ShapeT, DrawStrategy>;
        m_pimpl = std::make_unique<Model>(std::move(shape), std::move(drawer));
    }

    /**
     * Prototypeパターンを用いることで具象クラスを知らないままコピーが得られる
     */
    Shape(const Shape& other) : m_pimpl(other.m_pimpl->clone()) {}

    /**
     * Copy-and-Swap イディオム
     */
    Shape& operator=(const Shape& other) {
        Shape copy(other);           // コピーコンストラクト
        m_pimpl.swap(copy.m_pimpl);  // unique_ptrのswap
        return *this;
    }

    /**
     * コンパイラの自動生成に任せる
     */
    ~Shape() = default;
    Shape(Shape&&) = default;
    Shape& operator=(Shape&&) = default;

   private:
    /**
     * Shapeクラスのprivateメンバにアクセスできるフリー関数。
     * メンバ関数ではなくフリー関数にすることで、
     * draw()を切り出して依存関係を削減する。
     */
    friend void draw(const Shape& shape) { shape.m_pimpl->draw(); }

    friend bool operator==(const Shape& lhs, const Shape& rhs) {
        return lhs.m_pimpl->isEqual(rhs.m_pimpl.get());
    }

    friend bool operator!=(const Shape& lhs, const Shape& rhs) {
        return !(rhs == lhs);
    }

   private:
    std::unique_ptr<detail::ShapeConcept> m_pimpl;
};

#endif
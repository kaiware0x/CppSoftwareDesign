#ifndef DETAIL_H
#define DETAIL_H

#include <memory>
#include <utility>

/**
 * 実装詳細 (直接使用しないこと) を表す名前空間名
 */
namespace detail {

/**
 * 元々Shapeが持っていた仮想関数のセットを移動させてきたクラス。
 * Shapeの振る舞いを宣言するだけ。
 */
class ShapeConcept {
   public:
    virtual ~ShapeConcept() = default;

    virtual void draw() const = 0;

    /**
     * Prototypeパターンによるオブジェクトの複製
     */
    virtual std::unique_ptr<ShapeConcept> clone() const = 0;

    virtual bool isEqual(ShapeConcept const* c) const = 0;
};

struct DefaultDrawer {
    template <class T>
    void operator()(const T& obj) const {
        draw(obj);  // フリー関数へ転送する
    }
};

/**
 * 具体処理を転送する。またオブジェクトの複製を実装する。
 */
template <class ShapeT, class DrawStrategy>
class OwningShapeModel : public ShapeConcept {
   public:
    explicit OwningShapeModel(ShapeT shape, DrawStrategy drawer)
        : m_shape(std::move(shape)), m_drawer(std::move(drawer)) {}

    void draw() const override { m_drawer(m_shape); }

    std::unique_ptr<ShapeConcept> clone() const override {
        return std::make_unique<OwningShapeModel>(*this);
    }

    /**
     * Cons: Type Erasureは2項演算処理が苦手
     * この場合はdynamic_castを使っており遅い
     */
    bool isEqual(ShapeConcept const* c) const override {
        using Model = OwningShapeModel<ShapeT, DrawStrategy>;

        // 親→子へのキャスト
        // 実装例だとdynamic_castだがstatic_castではだめなのか？
        auto const* model = dynamic_cast<Model const*>(c);
        // auto const* model = static_cast<Model const*>(c);

        if (!model) {
            return false;
        }
        return (m_shape == model->m_shape);
    }

   private:
    ShapeT m_shape;
    DrawStrategy m_drawer;
};

}  // namespace detail

#endif
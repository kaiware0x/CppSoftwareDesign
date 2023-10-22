#ifndef SHAPE_H
#define SHAPE_H

/**
 * 元々Shapeが持っていた仮想関数のセットを移動させてきたクラス。
 * Shapeの振る舞いを宣言するだけ。
 */
class ShapeConcept {
   public:
    virtual ~ShapeConcept() = default;

    virtual void draw() const = 0;
};

struct DefaultDrawer {
    template <class T>
    void operator()(const T& obj) const {
        draw(obj);  // フリー関数へ転送する
    }
};

/**
 * 描画の要求を実際の実装(Strategy)へ転送するだけ
 */
template <class ShapeT, class DrawStrategy = DefaultDrawer>
class ShapeModel : public ShapeConcept {
   public:
    explicit ShapeModel(ShapeT shape, DrawStrategy drawer = DefaultDrawer{})
        : m_shape(std::move(shape)), m_drawer(std::move(drawer)) {}

    void draw() const override { m_drawer(m_shape); }

   private:
    ShapeT m_shape;
    DrawStrategy m_drawer;
};

#endif
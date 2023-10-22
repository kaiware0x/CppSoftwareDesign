#ifndef CIRCLE_H
#define CIRCLE_H

#include <functional>
#include <memory>
#include <utility>

#include "Shape.h"

/// @brief アーキテクチャ中位：Strategyと抽象Shapeに依存している
class Circle : public Shape {
   public:
    using DrawStrategy = std::function<void(const Circle&)>;

    /// @brief
    /// Cons:
    /// Serialize機能など他の機能をつけようとすると
    /// DIオブジェクトが増える(コンストラクタ引数が増える)
    /// @param radius
    /// @param drawer 依存性注入 (DI; Dependency Injection)
    explicit Circle(const double& radius, DrawStrategy drawer)
        : Shape(), m_radius(radius), m_drawer(std::move(drawer)) {}

    void draw() const override { m_drawer(*this); }

   private:
    double m_radius;

    DrawStrategy m_drawer;
};

#endif

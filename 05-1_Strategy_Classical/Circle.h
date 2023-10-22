#ifndef CIRCLE_H
#define CIRCLE_H

#include <memory>

#include "DrawStrategy.h"
#include "Shape.h"

/// @brief アーキテクチャ中位：Strategyと抽象Shapeに依存している
class Circle : public Shape {
   public:
    /// @brief
    /// Cons:
    /// Serialize機能など他の機能をつけようとすると
    /// DIオブジェクトが増える(コンストラクタ引数が増える)
    /// @param radius
    /// @param drawer 依存性注入 (DI; Dependency Injection)
    explicit Circle(const double& radius,
                    std::unique_ptr<DrawStrategy<Circle>> drawer)
        : Shape(), m_radius(radius), m_drawer(std::move(drawer)) {}

    void draw() const override { m_drawer->draw(*this); }

   private:
    double m_radius;

    std::unique_ptr<DrawStrategy<Circle>> m_drawer;
};

#endif

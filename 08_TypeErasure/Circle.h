#ifndef CIRCLE_H
#define CIRCLE_H

/**
 * 継承も外部への依存もなく、純粋にCircleのパラメータを持つだけのクラスになった！
 */
class Circle {
   public:
    explicit Circle(const double& radius) : m_radius(radius) {}

    auto radius() const { return m_radius; }

   private:
    double m_radius;
};

bool operator==(const Circle& lhs, const Circle& rhs) {
    return lhs.radius() == rhs.radius();
}

#endif

#ifndef SQUARE_H
#define SQUARE_H

/**
 * 継承も外部への依存もなく、純粋にSquareのパラメータを持つだけのクラスになった！
 */
class Square {
   public:
    explicit Square(const double& side) : m_side(side) {}

    auto side() const { return m_side; }

   private:
    double m_side;
};

#endif

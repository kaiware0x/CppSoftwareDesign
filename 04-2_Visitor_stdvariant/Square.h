#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"

class Square {
   public:
    explicit Square(double side) : m_side(side) {}

    auto side() const { return m_side; }
    auto center() const { return m_center; }

   private:
    double m_side;
    Point m_center;
};

#endif  // SQUARE_H

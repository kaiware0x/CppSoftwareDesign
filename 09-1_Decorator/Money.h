#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money {
   public:
    Money() {}
    Money(double value) : m_value(value) {}
    ~Money() = default;

    double value() const { return m_value; }

   private:
    double m_value{0.0};
};
Money operator*(Money money, double factor) {
    return Money(money.value() * factor);
}
Money operator+(Money lhs, Money rhs) {
    return Money(lhs.value() + rhs.value());
}
std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << money.value();
    return os;
}
#endif  // MONEY_H
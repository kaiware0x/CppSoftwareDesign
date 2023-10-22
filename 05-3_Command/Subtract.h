#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "CalculatorCommand.h"

class Subtract : public CalculatorCommand {
   public:
    explicit Subtract(const int& operand)
        : CalculatorCommand(), m_operand(operand) {}

    int execute(const int& i) const override { return i - m_operand; }
    int undo(const int& i) const override { return i + m_operand; }

   private:
    int m_operand{};
};

#endif
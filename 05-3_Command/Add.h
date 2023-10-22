#ifndef ADD_H
#define ADD_H

#include "CalculatorCommand.h"

class Add : public CalculatorCommand {
   public:
    explicit Add(const int& operand)
        : CalculatorCommand(), m_operand(operand) {}

    int execute(const int& i) const override { return i + m_operand; }
    int undo(const int& i) const override { return i - m_operand; }

   private:
    int m_operand{};
};

#endif
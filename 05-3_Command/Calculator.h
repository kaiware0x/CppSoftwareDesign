#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <memory>
#include <stack>

#include "CalculatorCommand.h"

class Calculator {
   public:
    void compute(std::unique_ptr<CalculatorCommand> command) {
        m_current = command->execute(m_current);
        m_stack.push(std::move(command));
    }

    void undoLast() {
        if (m_stack.empty()) {
            return;
        }

        auto command = std::move(m_stack.top());
        m_stack.pop();

        m_current = command->undo(m_current);
    }

    int result() const { return m_current; }

    void clear() {
        m_current = 0;
        CommandStack{}.swap(m_stack);
    }

   private:
    int m_current{};

    using CommandStack = std::stack<std::unique_ptr<CalculatorCommand>>;
    CommandStack m_stack;
};

#endif
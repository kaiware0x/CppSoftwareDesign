#ifndef CALCULATOR_COMMAND_H
#define CALCULATOR_COMMAND_H

class CalculatorCommand {
   public:
    virtual ~CalculatorCommand() = default;
    virtual int execute(const int& i) const = 0;
    virtual int undo(const int& i) const = 0;
};

#endif
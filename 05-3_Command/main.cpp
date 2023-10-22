#include <iostream>

#include "Add.h"
#include "Calculator.h"
#include "Subtract.h"

int main(int argc, char const *argv[]) {
    /// クライアント
    Calculator calculator{};

    /// アルゴリズム
    auto op1 = std::make_unique<Add>(3);
    auto op2 = std::make_unique<Add>(7);
    auto op3 = std::make_unique<Subtract>(4);
    auto op4 = std::make_unique<Subtract>(2);

    /// クライアントがアルゴリズムを実行する(Strategyと同じ構成)
    calculator.compute(std::move(op1));
    calculator.compute(std::move(op2));
    calculator.compute(std::move(op3));
    calculator.compute(std::move(op4));

    calculator.undoLast();

    std::cout << calculator.result() << std::endl;

    return 0;
}

/* Note:
以下2つのデザインパターンはクラス関係がほぼ同じ

Strategy
- 何をどう行うか(How) を表す
- DIをしていたらほぼStrategy

Command
- 何を行うか(What) を表す
- オブジェクトに動作を設定せず、直接実行していたらほぼCommand

*/

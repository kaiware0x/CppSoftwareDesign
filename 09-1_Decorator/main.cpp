#include <cstdlib>
#include <iostream>
#include <memory>

#include "ConferenceTicket.h"
#include "CppBook.h"
#include "Discounted.h"
#include "Taxed.h"

int main(int argc, char const *argv[]) {
    // 税率7% -> 19*1.07 = 20.33 ドル
    std::unique_ptr<Item> item1(std::make_unique<Taxed>(
        0.07, std::make_unique<CppBook>("Effective C++", 19.0)));

    // 割引20%, 税率19% -> (999*0.8)*1.19 = 951.05 ドル
    std::unique_ptr<Item> item2(  //
        std::make_unique<Taxed>(
            0.19,  // 税率19%
            std::make_unique<Discounted>(
                0.2,  // 割引20%
                std::make_unique<ConferenceTicket>("CppCon", 999.0))));

    std::cout << item1->price() << std::endl;
    std::cout << item2->price() << std::endl;
    return 0;
}

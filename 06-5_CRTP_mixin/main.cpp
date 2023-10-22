#include <cstdlib>
#include <iostream>

#include "Distances.h"
#include "Person.h"

int main(int argc, char const *argv[]) {
    const auto m1 = Meter<long>{100};
    const auto m2 = Meter<long>{50};

    std::cout << (m1 + m2) << std::endl;

    const auto km = KiloMeter<long>{30};
    // m1 + km; // error!

    auto surname1 = Surname{"AAA"};
    auto surname2 = Surname{"BBB"};
    // surname1 + surname2;  // error!

    return 0;
}

#ifndef ADDRESS_OBSERVER_H
#define ADDRESS_OBSERVER_H

#include <iostream>

#include "Observer.h"
#include "Person.h"

class AddressObserver : public Person::PersonObserver {
   public:
    void update(const Person &person, Person::StateChange property) override {
        if (property == Person::addressChanged) {
            std::cout << "Update AddressObserver ... Address: "
                      << person.address() << std::endl;
        }
    }
};

#endif
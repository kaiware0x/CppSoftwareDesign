#ifndef NAME_OBSERVER_H
#define NAME_OBSERVER_H

#include <iostream>

#include "Observer.h"
#include "Person.h"

class NameObserver : public Person::PersonObserver {
   public:
    void update(const Person &person, Person::StateChange property) override {
        if (property == Person::forenameChanged ||
            property == Person::surnameChanged) {
            /// Respond to changed name...
            std::cout << "Update NameObserver ... Forename: "
                      << person.forename() << ", Surname: " << person.surname()
                      << std::endl;
        }
    }
};

#endif

#include <iostream>

#include "AddressObserver.h"
#include "NameObserver.h"
#include "Person.h"

int main() {
    NameObserver name_observer;
    AddressObserver address_observer;

    Person homer("Homer", "Simpson");
    Person marge("Marge", "Simpson");
    Person monty("Montgomery", "Burns");

    /// Personに対して観測者(Observer)をセットしていく.
    homer.attach(&name_observer);
    marge.attach(&address_observer);
    monty.attach(&address_observer);

    /// Updating
    /// Observerに対して状態変化の通知が飛ぶ.
    homer.forename("Homer Jay");
    marge.address("712 Red Bark");
    monty.address("Springfield");

    /// Detaching observers
    homer.detach(&name_observer);

    return 0;
}

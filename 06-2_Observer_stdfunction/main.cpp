
#include <iostream>

#include "Observer.h"
#include "Person.h"

void propertyChanged(const Person& person, Person::StateChange property) {
    if (property == Person::forenameChanged) {
        std::cout << "forename changed\n";
    }
}

int main() {
    using PersonObserver = Observer<Person, Person::StateChange>;

    PersonObserver name_observer{propertyChanged};
    PersonObserver address_observer{
        [](const Person& person, Person::StateChange property) {
            if (property == Person::addressChanged) {
                std::cout << "address changed\n";
            }
        }};

    Person homer("Homer", "Simpson");
    Person marge("Marge", "Simpson");
    Person monty("Montgomery", "Burns");

    /// Personに対して観測者(Observer)をセットしていく.
    homer.attach(&name_observer);
    homer.attach(&address_observer);
    marge.attach(&address_observer);
    monty.attach(&address_observer);

    /// Updating
    /// Observerに対して状態変化の通知が飛ぶ.
    homer.forename("Homer Jay");
    homer.address("Tokyo");
    marge.address("712 Red Bark");
    monty.address("Springfield");

    /// Detaching observers
    homer.detach(&name_observer);

    return 0;
}

/*
std::functionを用いた実装

Pros:
- コールバックを外部から与えられる
    - 関心の分離ができている

Cons:
- update()を1つしか持たないプルオブザーバに限られる
    - 複数のupdate()を持つプッシュオブザーバでは使えない
- 純粋な値ベースの実装ではない
    - SubjectにObserverのポインタを渡している
- スレッドセーフ処理の実装が必要

その他:
- Observerを多数用いるとエンティティ間の通信がすぐに複雑化する

*/

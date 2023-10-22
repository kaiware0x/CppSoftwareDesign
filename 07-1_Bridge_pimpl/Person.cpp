#include "Person.h"

#include <string>

struct Person::Impl {
    std::string forename;
    std::string surname;
    std::string address;
    std::string city;
    std::string country;
    std::string zip;
    int year_of_birth;
};

Person::Person() : m_pimpl(std::make_unique<Impl>()) {}

/**
.hにはImplの定義が無いため、Personのデストラクタは.cpp内で定義する必要がある
*/
Person::~Person() = default;

Person::Person(const Person& other)
    : m_pimpl(std::make_unique<Impl>(*other.m_pimpl)) {}

Person& Person::operator=(const Person& other) {
    *m_pimpl = *other.m_pimpl;
    return *this;
}

Person::Person(Person&& other)
    : m_pimpl(std::make_unique<Impl>(std::move(*other.m_pimpl))) {}

Person& Person::operator=(Person&& other) {
    *m_pimpl = std::move(*other.m_pimpl);
    return *this;
}

int Person::year_of_birth() const { return m_pimpl->year_of_birth; }

/**

Pros:
- クラス間の物理的な依存を隠蔽できる

Cons:
- 間接参照が発生する
- 場合によっては仮想関数コールが入る
- メンバ関数のインライン展開が行われなくなる
- pimplポインタの動的メモリ割り当てが入る
- pimplポインタのメモリオーバーヘッドがある
- .hは簡素になるが、.cppが複雑化する
*/
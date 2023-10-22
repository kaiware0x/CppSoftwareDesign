#ifndef PERSON_H
#define PERSON_H

#include <memory>

class Person {
   public:
    Person();
    ~Person();

    Person(const Person& other);
    Person& operator=(const Person& other);

    Person(Person&& other);
    Person& operator=(Person&& other);

    int year_of_birth() const;

   private:
    /*
    実装詳細を.cppファイルに押し付けられる。
    */
    struct Impl;
    std::unique_ptr<Impl> const m_pimpl;
};

#endif


#ifndef PERSON_H
#define PERSON_H

#include <set>
#include <string>

#include "Observer.h"

class Person {
   public:
    enum StateChange { forenameChanged, surnameChanged, addressChanged };

    using PersonObserver = Observer<Person, StateChange>;

    explicit Person(std::string forename, std::string surname)
        : m_forename(forename), m_surname(surname) {}

    /// @brief 登録する
    /// @param observer
    /// @return
    bool attach(PersonObserver *observer) {
        auto [pos, success] = m_observers.insert(observer);
        return success;
    }

    /// @brief 登録解除
    /// @param observer
    /// @return
    bool detach(PersonObserver *observer) {
        std::cout << "detach" << std::endl;
        return (m_observers.erase(observer) > 0u);
    }

    /// @brief 登録してあるObserverに変化を通知する.
    /// @param property
    void notify(const StateChange property) {
        for (auto iter = std::begin(m_observers);
             iter != std::end(m_observers);) {
            const auto pos = iter++;
            (*pos)->update(*this, property);
        }
    }

    void forename(std::string new_forename) {
        m_forename = new_forename;
        notify(forenameChanged);
    }
    void surname(std::string new_surname) {
        m_surname = new_surname;
        notify(surnameChanged);
    }
    void address(std::string new_address) {
        m_address = new_address;
        notify(addressChanged);
    }

    const std::string &forename() const { return m_forename; }
    const std::string &surname() const { return m_surname; }
    const std::string &address() const { return m_address; }

   private:
    std::string m_forename;
    std::string m_surname;
    std::string m_address;

    std::set<PersonObserver *> m_observers;
};

#endif
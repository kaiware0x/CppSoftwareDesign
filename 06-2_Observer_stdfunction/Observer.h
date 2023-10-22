#ifndef OBSERVER_H
#define OBSERVER_H

#include <functional>

template <class Subject, class StateTag>
class Observer {
   public:
    using OnUpdate = std::function<void(const Subject &, StateTag)>;

    Observer(OnUpdate on_update) : m_on_update{std::move(on_update)} {}

    void update(const Subject &subject, StateTag property) {
        m_on_update(subject, property);
    }

   private:
    OnUpdate m_on_update;
};

#endif
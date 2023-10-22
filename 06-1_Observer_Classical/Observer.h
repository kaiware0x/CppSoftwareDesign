#ifndef OBSERVER_H
#define OBSERVER_H

template <class Subject, class StateTag>
class Observer {
   public:
    virtual ~Observer() = default;
    virtual void update(const Subject &subject, StateTag property) = 0;
};

#endif
#ifndef SWAPPABLE_H
#define SWAPPABLE_H

template <typename Derived>
struct Swappable {
    friend void swap(Derived& lhs, Derived& rhs) {
        using std::swap;  // Enable ADL
        swap(lhs, rhs);
    }
};

#endif
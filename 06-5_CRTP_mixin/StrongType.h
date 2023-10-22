#ifndef STRONG_TYPE_H
#define STRONG_TYPE_H

#include <cstdlib>
#include <utility>

// template <typename T, typename Tag, class... Skills>
// struct StrongType : private T, private Tag, private Skills... {
template <typename T, typename Tag, template <typename> class... Skills>
struct StrongType : private Skills<StrongType<T, Tag, Skills...>>... {
   public:
    using value_type = T;
    explicit StrongType(const T& value) : m_value(value) {}

    T& get() { return m_value; }
    const T& get() const { return m_value; }

   private:
    T m_value;
};

#endif
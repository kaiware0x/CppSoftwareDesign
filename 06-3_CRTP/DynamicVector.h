#ifndef DYNAMIC_VECTOR_H
#define DYNAMIC_VECTOR_H

#include <iosfwd>
#include <iterator>
#include <numeric>
#include <vector>

/// @brief メモリを動的に割り当てるVector
/// @tparam T
template <typename T>
class DynamicVector {
   public:
    using value_type = T;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    size_t size() const;

    T& operator[](size_t index);
    T const& operator[](size_t index) const;

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

   private:
    std::vector<T> m_values;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, DynamicVector<T> const& vector) {
    os << "(";
    for (const auto& elem : vector) {
        os << " " << elem;
    }
    os << ")";
}

template <typename T>
auto l2norm(const DynamicVector<T>& vector) {
    using std::begin, std::end;
    return std::sqrt(
        std::inner_product(begin(vector), end(vector), begin(vector), T{}));
}

#endif
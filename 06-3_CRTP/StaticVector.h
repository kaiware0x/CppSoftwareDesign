#ifndef STATIC_VECTOR_H
#define STATIC_VECTOR_H

#include <array>
#include <iosfwd>
#include <iterator>
#include <numeric>

/// @brief メモリを静的に割り当てるVector
/// @tparam T
template <typename T, size_t Size>
class StaticVector {
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
    std::array<T, Size> m_values;
};

template <typename T, size_t Size>
std::ostream& operator<<(std::ostream& os,
                         StaticVector<T, Size> const& vector) {
    os << "(";
    for (const auto& elem : vector) {
        os << " " << elem;
    }
    os << ")";
}

template <typename T, size_t Size>
auto l2norm(const StaticVector<T, Size>& vector) {
    using std::begin, std::end;
    return std::sqrt(
        std::inner_product(begin(vector), end(vector), begin(vector), T{}));
}

#endif
#ifndef DENSE_VECTOR_H
#define DENSE_VECTOR_H

#include <concepts>
#include <iostream>
#include <numeric>

struct DenseVectorTag {};

template <typename T>
struct IsDenseVector : public std::is_base_of<DenseVectorTag, T> {};

template <typename T>
constexpr bool IsDenseVector_v = IsDenseVector<T>::value;

template <typename T>
concept DenseVector =
    /// Tにiteratorなど一般コンテナの制約を付与する。
    requires(T t, size_t index) {
        t.size();
        t[index];
        { t.begin() } -> std::same_as<typename T::iterator>;
        { t.end() } -> std::same_as<typename T::iterator>;
    } &&
    /// Tにconst_iteratorなど一般コンテナの制約を付与する。
    requires(const T t, size_t index) {
        t[index];
        { t.begin() } -> std::same_as<typename T::const_iterator>;
        { t.end() } -> std::same_as<typename T::const_iterator>;
    } &&
    /// TはDenseVectorTagを継承している必要がある。
    /// これによってTにstd::vectorやstd::stringを入れられなくできる。
    std::is_base_of_v<DenseVectorTag, T> &&
    /// 型特性IsDenseVectorを介して、DenseVector conceptが間接的に型を確認する。
    IsDenseVector_v<T>;

template <DenseVector VectorT>
std::ostream& operator<<(std::ostream& os, const VectorT& vector) {
    os << "(";
    for (const auto& elem : vector) {
        os << " " << elem;
    }
    os << ")";
    return os;
}
#endif

#ifndef STATIC_VECTOR_H
#define STATIC_VECTOR_H

#include "DenseVector.h"

template <typename T, size_t Size>
class StaticVector {
    /* must impl
    size()
    operator[]
    begin()
    end()
    */
};

/**
std::true_typeを継承してIsDenseVectorを特殊化。
これによってDenseVector conceptを満たせる。
DynamicVectorのようなTagを継承する方法と比べて、
こちらのほうは既存コードに干渉しないというメリットがある。
*/
template <typename T, size_t Size>
struct IsDenseVector<StaticVector<T, Size>> : public std::true_type {};

#endif

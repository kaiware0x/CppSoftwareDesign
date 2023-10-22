#ifndef DYNAMIC_VECTOR_H
#define DYNAMIC_VECTOR_H

#include "DenseVector.h"

/// @brief DenseVectorTagを継承することでDenseVector conceptを満たせる。
/// @tparam T
template <typename T>
class DynamicVector : private DenseVectorTag {
    /// some impl
};

#endif
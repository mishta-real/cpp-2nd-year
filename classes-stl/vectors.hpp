#ifndef VECTORS_HPP
#define VECTORS_HPP

#include <vector> // std::vector

namespace Vectors {

template <typename VectorType>
const size_t count_n(
        const std::vector<VectorType> &vector,
        const VectorType n
);

template <typename VectorType>
const std::vector<size_t> indices_of_n(
        const std::vector<VectorType> &vector,
        const VectorType n
);

const size_t count_even(
        const std::vector<int> &vector
);

const std::vector<size_t> indices_of_even(
        const std::vector<int> &vector
);

const int sum_even_of(
        const std::vector<int> &vector
);
const int sum_all_of(
        const std::vector<int> &vector
);

template <typename VectorType>
void sort(
        std::vector<VectorType> &vector
);

template <typename VectorType>
void swap_edges(
        std::vector<VectorType> &vector
);

template <typename VectorType>
void print(
        const std::vector<VectorType> &vector
);

} // namespace Vectors

#endif

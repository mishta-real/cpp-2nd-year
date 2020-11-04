#ifndef VECTORS_HPP
#define VECTORS_HPP

#include <algorithm> // std::count(), std::count_if(), std::find(), std::find_if(), std::swap(), std::is_sorted(), std::sort()
#include <iostream> // std::cout
#include <iterator> // std::distance()
#include <numeric> // std::accumulate()
#include <vector> // std::vector

const bool is_even(
        const int n
) {
    return !(n % 2);
}

namespace Vectors {

template <typename VectorType>
const size_t count_n(
        const std::vector<VectorType> &vector,
        const VectorType n
) {
    return std::count( vector.cbegin(), vector.cend(), n );
}

template <typename VectorType>
const std::vector<size_t> indices_of_n(
        const std::vector<VectorType> &vector,
        const VectorType n
) {
    std::vector<size_t> indices;

    for ( size_t i = 0; i < vector.size(); ++i ) {
        if ( vector[ i ] == n ) {
            indices.push_back( i );
        }
    }

    return indices;
}

const size_t count_even(
        const std::vector<int> &vector
) {
    return std::count_if( vector.cbegin(), vector.cend(), is_even );
}

const std::vector<size_t> indices_of_even(
        const std::vector<int> &vector
) {
    std::vector<size_t> indices;

    for ( size_t i = 0; i < vector.size(); ++i ) {
        if ( is_even( vector[ i ] ) ) {
            indices.push_back( i );
        }
    }

    return indices;
}

const int sum_even_of(
        const std::vector<int> &vector
) {
    int sum = 0;

    for ( auto it = vector.cbegin(); it != vector.cend(); ++it ) {
        if ( is_even( *it ) ) {
            sum += *it;
        }
    }

    return sum;
}

const int sum_all_of(
        const std::vector<int> &vector
) {
    return std::accumulate( vector.cbegin(), vector.cend(), 0 );
}

template <typename VectorType>
void sort(
        std::vector<VectorType> &vector
) {
    if ( !std::is_sorted( vector.begin(), vector.end() ) ) {
        std::sort( vector.begin(), vector.end() );
    }
}

template <typename VectorType>
void swap_edges(
        std::vector<VectorType> &vector
) {
    std::swap( *vector.begin(), *(vector.end() - 1) );
}

template <typename VectorType>
void print(
        const std::vector<VectorType> &vector
) {
    if ( !vector.empty() ) {
        for ( auto it = vector.cbegin(); it < vector.cend() - 1; ++it ) {
            std::cout << *it << " ";
        }

        std::cout << *(vector.cend() - 1);
    }
    else {
        std::cerr
            << "Could not print vector: vector is empty."
            << std::endl;
    }
}

} // namespace Vectors

#endif

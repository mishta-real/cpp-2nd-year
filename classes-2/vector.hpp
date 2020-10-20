#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "complex.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <initializer_list>

namespace Vector {

template <typename T>
class Vector;

template <typename T>
std::ostream &operator<<(
        std::ostream &t_ostream,
        const Vector<T> &t_vector
);

/*
 * Shortened version of original class Vector: only length() function needed.
 * Focusing on templates.
 *
 * Full version is in 'classes-1' directory.
*/
template <typename T>
class Vector {

public:
    Vector( const int t_size=1 );
    Vector<T>( const std::initializer_list<T> list );
    ~Vector();

    friend std::ostream &operator<< <T>(
            std::ostream &t_ostream,
            const Vector<T> &t_vector
    );

    double length() const;
    size_t size() const;

private:
    T *m_vector;
    size_t m_size;

}; // class Vector

template <typename T>
Vector<T>::Vector( const int t_size )
{
    if ( t_size > 0 ) {
        m_size = t_size;
        m_vector = new T[ m_size ];

        for ( unsigned i = 0; i < m_size; ++i ) {
            m_vector[ i ] = 0;
        }
    }
    else {
        std::cerr
            << "Negative vector size was given while instantiation. Exit."
            << std::endl;
        std::exit( 1 );
    }
}

template <>
Vector<Complex::Complex>::Vector( const int t_size )
{
    if ( t_size > 0 ) {
        m_size = t_size;
        m_vector = new Complex::Complex[ m_size ];

        for ( unsigned i = 0; i < m_size; ++i ) {
            m_vector[ i ] = Complex::Complex();
        }
    }
    else {
        std::cerr
            << "Negative vector size was given while instantiation. Exit."
            << std::endl;
        std::exit( 1 );
    }

}

template <typename T>
Vector<T>::Vector( const std::initializer_list<T> list )
    : Vector<T>( static_cast<int>( list.size() ) )
{
    unsigned i = 0;

    for ( const T &elem : list ) {
        m_vector[ i ] = elem;
        ++i;
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_vector;
}

template <typename T>
double Vector<T>::length() const
{
    if ( m_size > 2 ) {
        double length = 0;

        for ( unsigned i = 0; i < m_size; ++i ) {
            length += std::pow( m_vector[ i ], 2 );
        }

        return std::sqrt( length );
    }
    else if ( m_size == 2 ) {
        return std::hypot( m_vector[ 0 ], m_vector[ 1 ] );
    }
    else if ( m_size == 1 ) {
        return std::abs( m_vector[ 0 ] );
    }
    else if ( !m_size ) {
        return 0;
    }
    else {
        std::cerr << "Vector size is somehow negative. Exit." << std::endl;
        std::exit( 1 );
    }
}

template<>
double Vector<Complex::Complex>::length() const
{
    if ( m_size > 2 ) {
        double length = 0;

        for ( unsigned i = 0; i < m_size; ++i ) {
            ++length;
        }

        return length;
    }
    else {
        std::cerr << "Vector size is somehow negative. Exit." << std::endl;
        std::exit( 1 );
    }
}

template <typename T>
size_t Vector<T>::size() const
{
    return m_size;
}

template <typename T>
std::ostream &operator<<(
        std::ostream &t_ostream,
        const Vector<T> &t_vector
) {
    t_ostream << '(';

    for ( unsigned i = 0; i < t_vector.size() - 1; ++i ) {
        t_ostream << t_vector.m_vector[ i ] << ", ";
    }

    t_ostream << t_vector.m_vector[ t_vector.size() - 1 ] << ')';

    return t_ostream;
}

} // namespace Vector

#endif

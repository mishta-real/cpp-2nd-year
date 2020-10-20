#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "complex.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>
// #include <limits>

namespace Vector {

template <typename T>
class Vector;

template <typename T>
std::ostream &operator<<(
        std::ostream &t_ostream,
        const Vector<T> &t_vector
);

/*
template <typename T>
std::istream &operator>>(
        std::istream &t_istream,
        Vector<T> &t_vector
);
*/

template <typename T>
class Vector {

public:
    Vector( const int t_size=1 );
    Vector( const Vector<T> &t_vector );
    ~Vector();
    Vector<T> &operator=( const Vector<T> &t_vector );
/*
    T &operator[]( const int index );
    T &operator[]( const int index ) const;
    Vector<T> operator+( const Vector<T> &t_vector ) const;
    Vector<T> operator*( const double t_mul ) const;
    T operator*( const Vector<T> &t_vector ) const;

    bool operator>( const Vector<T> &t_vector ) const;
    bool operator<( const Vector<T> &t_vector ) const;
    bool operator>=( const Vector<T> &t_vector ) const;
    bool operator<=( const Vector<T> &t_vector ) const;
    bool operator==( const Vector<T> &t_vector ) const;
    bool operator!=( const Vector<T> &t_vector ) const;
*/
    friend std::ostream &operator<< <T>(
            std::ostream &t_ostream,
            const Vector<T> &t_vector
    );
/*
    friend std::istream &operator>> <T>(
            std::istream &t_istream,
            Vector<T> &t_vector
    );
*/
    double length() const;
    int size() const;

private:
    T *m_vector;
    int m_size;

}; // class Vector

template <typename T>
Vector<T>::Vector( const int t_size )
{
    if ( t_size > 0 ) {
        m_vector = new T[ t_size ];
        m_size = t_size;

        for ( int i = 0; i < m_size; ++i ) {
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

template <typename T>
Vector<T>::Vector( const Vector<T> &t_vector )
{
    m_vector = new T[ t_vector.m_size ];
    m_size = t_vector.m_size;

    for ( int i = 0; i < t_vector.m_size; ++i ) {
        m_vector[ i ] = t_vector.m_vector[ i ];
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_vector;
    m_vector = nullptr;
}

template <typename T>
Vector<T> &Vector<T>::operator=( const Vector<T> &t_vector )
{
    if ( this != &t_vector ) {

        if ( m_size != t_vector.m_size ) {
            delete[] m_vector;
        }

        m_vector = new T[ t_vector.m_size ];
        m_size = t_vector.m_size;

        for ( int i = 0; i < m_size; ++i ) {
            m_vector[ i ] = t_vector.m_vector[ i ];
        }
    }

    return *this;
}

/*
template <typename T>
T &Vector<T>::operator[]( const int index ) const
{
    if ( -1 < index && index < m_size ) {
        return m_vector[ index ];
    }
    else if ( index < 0 ) {
        std::cerr
            << "Can not get element at negative index. Exit."
            << std::endl;
        std::exit( 1 );
    }
    else {
        std::cerr
            << "The index is out of bounds. Exit."
            << std::endl;
        std::exit( 1 );
    }
}

template <typename T>
T &Vector<T>::operator[]( const int index )
{
    if ( -1 < index && index < m_size ) {
        return m_vector[ index ];
    }
    else if ( index < 0 ) {
        std::cerr
            << "Can not get element at negative index. Exit."
            << std::endl;
        std::exit( 1 );
    }
    else {
        std::cerr
            << "The index is out of bounds. Exit."
            << std::endl;
        std::exit( 1 );
    }
}

template <typename T>
Vector<T> Vector<T>::operator+( const Vector<T> &t_vector ) const
{
    Vector<T> vector_new = m_size >= t_vector.m_size ? *this : t_vector;

    for ( int i = 0; i < std::min( m_size, t_vector.m_size ); ++i ) {
        vector_new.m_vector[ i ] += t_vector.m_vector[ i ];
    }

    return vector_new;
}

template <typename T>
Vector<T> Vector<T>::operator*( const double t_mul ) const
{
    Vector<T> vector_new = *this;

    for ( int i = 0; i < vector_new.m_size; ++i ) {
        vector_new.m_vector[ i ] *= t_mul;
    }

    return vector_new;
}

template <typename T>
T Vector<T>::operator*( const Vector<T> &t_vector ) const
{
    T scalar_product = 0;

    for ( int i = 0; i < std::min( m_size, t_vector.m_size ); ++i ) {
        scalar_product += m_vector[ i ] * t_vector.m_vector[ i ];
    }

    return scalar_product;
}
*/

template <typename T>
double Vector<T>::length() const
{
    if ( m_size > 2 ) {
        double length = 0;

        for ( int i = 0; i < m_size; ++i ) {
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

        for ( int i = 0; i < m_size; ++i ) {
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
int Vector<T>::size() const
{
    return m_size;
}

/*
template <typename T>
bool Vector<T>::operator>( const Vector<T> &t_vector ) const
{
    return length() > t_vector.length();
}

template <typename T>
bool Vector<T>::operator<( const Vector<T> &t_vector ) const
{
    return length() < t_vector.length();
}

template <typename T>
bool Vector<T>::operator>=( const Vector<T> &t_vector ) const
{
    return length() >= t_vector.length();
}

template <typename T>
bool Vector<T>::operator<=( const Vector<T> &t_vector ) const
{
    return length() <= t_vector.length();
}

template <typename T>
bool Vector<T>::operator==( const Vector<T> &t_vector ) const
{
    return length() == t_vector.length();
}

template <typename T>
bool Vector<T>::operator!=( const Vector<T> &t_vector ) const
{
    return length() != t_vector.length();
}
*/

template <typename T>
std::ostream &operator<<(
        std::ostream &t_ostream,
        const Vector<T> &t_vector
) {
    t_ostream << '(';

    for ( int i = 0; i < t_vector.m_size - 1; ++i ) {
        t_ostream << t_vector.m_vector[ i ] << ", ";
    }

    t_ostream << t_vector.m_vector[ t_vector.m_size - 1 ] << ')';

    return t_ostream;
}

/*
template <typename T>
std::istream &operator>>(
        std::istream &t_istream,
        Vector<T> &t_vector
) {
    delete[] t_vector.m_vector;

    // First argument is the size of vector
    t_istream >> t_vector.m_size;

    if ( t_vector.m_size > 0 ) {
        t_vector.m_vector = new T[ t_vector.m_size ];

        for ( int i = 0; i < t_vector.m_size; ++i ) {
            t_istream >> t_vector.m_vector[ i ];

            // Validating the input
            if ( t_istream.bad() ) {
                std::cerr
                    << "Error while creating vector. Exit."
                    << std::endl;
                std::exit( 1 );
            }
            else if ( t_istream.fail() ) {
                // t_vector.vector[ i ] = 0;
                t_istream.clear();
                t_istream.ignore(
                    std::numeric_limits< std::streamsize >::max(),
                    '\n'
                );
            }
        }

        return t_istream;
    }
    else {
        std::cerr
            << "Vector size must be greater than 0. Exit."
            << std::endl;
        std::exit( 1 );
    }
}
*/

} // namespace Vector

#endif

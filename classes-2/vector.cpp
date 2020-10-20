#include "vector.hpp"

#include <complex>
#include <cstdlib>
#include <iostream>

template <class T>
Vector::Vector<T>( const int t_size )
{
    if ( t_size > 0 ) {
        this->m_vector = new double[ t_size ];
        this->m_size = t_size;

        for ( int i = 0; i < this->m_size; ++i ) {
            this->m_vector[ i ] = 0;
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
Vector::Vector<T>( const Vector<T> &t_vector )
{
    this->m_vector = new double[ t_vector.m_size ];
    this->m_size = t_vector.m_size;

    for ( int i = 0; i < t_vector.m_size; ++i ) {
        this->m_vector[ i ] = t_vector.m_vector[ i ];
    }
}

template <typename T>
Vector::~Vector<T>()
{
    delete[] this->m_vector;
    this->m_vector = nullptr;
}


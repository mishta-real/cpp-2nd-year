#include "constants.hpp"
#include "vector.hpp"

#include <algorithm> // std::min()
#include <cstdlib> // std::exit()
#include <cmath> // std::hypot(), std::sqrt(), std::pow()
#include <limits> // std::numeric_limits<std::streamsize>::max()

namespace Vector {

// =============== Constructors ===============

Vector::Vector( const int t_size )
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

Vector::Vector( const Vector &t_vector )
{
    this->m_vector = new double[ t_vector.m_size ];
    this->m_size = t_vector.m_size;

    for ( int i = 0; i < t_vector.m_size; ++i ) {
        this->m_vector[ i ] = t_vector.m_vector[ i ];
    }
}

Vector::~Vector()
{
    delete[] this->m_vector;
    this->m_vector = nullptr;
}

Vector &Vector::operator=( const Vector &t_vector )
{
    if ( this != &t_vector ) {

        if ( this->m_size != t_vector.m_size ) {
            delete[] m_vector;
        }

        this->m_vector = new double[ t_vector.m_size ];
        this->m_size = t_vector.m_size;

        for ( int i = 0; i < this->m_size; ++i ) {
            this->m_vector[ i ] = t_vector.m_vector[ i ];
        }

    }

    return *this;
}

// =============== Arithmetical operators ===============

double &Vector::operator[]( const int index ) const
{
    if ( -1 < index && index < this->m_size ) {
        return this->m_vector[ index ];
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

double &Vector::operator[]( const int index )
{
    if ( -1 < index && index < this->m_size ) {
        return this->m_vector[ index ];
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

Vector Vector::operator+( const Vector &t_vector ) const
{
    Vector vector_new = this->m_size >= t_vector.m_size ? *this : t_vector;

    for ( int i = 0; i < std::min( this->m_size, t_vector.m_size ); ++i ) {
        vector_new.m_vector[ i ] += t_vector.m_vector[ i ];
    }

    return vector_new;
}

Vector Vector::operator*( const double t_mul ) const
{
    Vector vector_new = *this;

    for ( int i = 0; i < vector_new.m_size; ++i ) {
        vector_new.m_vector[ i ] *= t_mul;
    }

    return vector_new;
}


double Vector::operator*( const Vector &t_vector ) const
{
    double scalar_product = 0;

    for ( int i = 0; i < std::min( this->m_size, t_vector.m_size ); ++i ) {
        scalar_product += this->m_vector[ i ] * t_vector.m_vector[ i ];
    }

    return scalar_product;
}

double Vector::length() const
{
    if ( this->m_size > 2 ) {
        double length = 0;

        for ( int i = 0; i < this->m_size; ++i ) {
            length += std::pow( this->m_vector[ i ], 2 );
        }

        return std::sqrt( length );
    }
    else if ( this->m_size == 2 ) {
        return std::hypot( this->m_vector[ 0 ], this->m_vector[ 1 ] );
    }
    else if ( this->m_size == 1 ) {
        return std::abs( this->m_vector[ 0 ] );
    }
    else if ( !this->m_size ) {
        return 0;
    }
    else {
        std::cerr << "Vector size is somehow negative. Exit." << std::endl;
        std::exit( 1 );
    }
}

// =============== Relational operators ===============

bool Vector::operator>( const Vector &t_vector ) const
{
    return this->length() > t_vector.length();
}

bool Vector::operator<( const Vector &t_vector ) const
{
    return this->length() < t_vector.length();
}

bool Vector::operator>=( const Vector &t_vector ) const
{
    return this->length() >= t_vector.length();
}

bool Vector::operator<=( const Vector &t_vector ) const
{
    return this->length() <= t_vector.length();
}

bool Vector::operator==( const Vector &t_vector ) const
{
    return this->length() == t_vector.length();
}

bool Vector::operator!=( const Vector &t_vector ) const
{
    return this->length() != t_vector.length();
}

// =============== Input/output operators ===============

std::ostream &operator<<( std::ostream &t_ostream, const Vector &t_vector )
{
    t_ostream << '(';

    for ( int i = 0; i < t_vector.m_size - 1; ++i ) {
        t_ostream << t_vector.m_vector[ i ] << ", ";
    }

    t_ostream << t_vector.m_vector[ t_vector.m_size - 1 ] << ')';

    return t_ostream;
}

std::istream &operator>>( std::istream &t_istream, Vector &t_vector )
{
    delete[] t_vector.m_vector;

    // First argument is the size of vector
    t_istream >> t_vector.m_size;

    if ( t_vector.m_size > 0 ) {
        t_vector.m_vector = new double[ t_vector.m_size ];

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

int Vector::get_size() const
{
    return this->m_size;
}

double angle( const Vector v1, const Vector v2 )
{
    const double l1 = v1.length();
    const double l2 = v2.length();

    if ( l1 != 0.0 && l2 != 0.0 ) {
        return (std::acos( (v1 * v2) / (l1 * l2) ) * 180.0) / PI;
    }
    else {
        return 0.0;
    }
}

} // namespace Vector

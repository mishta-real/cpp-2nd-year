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
        this->vector = new double[ t_size ];

        for ( int i = 0; i < t_size; ++i ) {
            this->vector[ i ] = 0;
        }

        this->size = t_size;
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
    this->vector = new double[ t_vector.size ];

    for ( int i = 0; i < t_vector.size; ++i ) {
        this->vector[ i ] = t_vector.vector[ i ];
    }

    this->size = t_vector.size;
}

Vector::~Vector()
{
    delete[] this->vector;
    this->vector = nullptr;
}

Vector &Vector::operator=( const Vector &t_vector )
{
    if ( this != &t_vector ) {

        if ( this->size != t_vector.size ) {
            delete[] vector;
        }

        this->vector = new double[ t_vector.size ];

        for ( int i = 0; i < t_vector.size; ++i ) {
            this->vector[ i ] = t_vector.vector[ i ];
        }

        size = t_vector.size;
    }

    return *this;
}

// =============== Arithmetical operators ===============

double &Vector::operator[]( const int index ) const
{
    if ( -1 < index && index < this->size ) {
        return this->vector[ index ];
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
    if ( -1 < index && index < this->size ) {
        return this->vector[ index ];
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
    Vector vector_new = this->size >= t_vector.size ? *this : t_vector;

    for ( int i = 0; i < std::min( this->size, t_vector.size ); ++i ) {
        vector_new.vector[ i ] += t_vector.vector[ i ];
    }

    return vector_new;
}

Vector Vector::operator*( const double t_mul ) const
{
    Vector vector_new = *this;

    for ( int i = 0; i < vector_new.size; ++i ) {
        vector_new.vector[ i ] *= t_mul;
    }

    return vector_new;
}


double Vector::operator*( const Vector &t_vector ) const
{
    double scalar_product = 0;

    for ( int i = 0; i < std::min( this->size, t_vector.size ); ++i ) {
        scalar_product += this->vector[ i ] * t_vector.vector[ i ];
    }

    return scalar_product;
}

double Vector::length() const
{
    if ( this->size > 2 ) {
        double length = 0;

        for ( int i = 0; i < this->size; ++i ) {
            length += std::pow( this->vector[ i ], 2 );
        }

        return std::sqrt( length );
    }
    else if ( this->size == 2 ) {
        return std::hypot( this->vector[ 0 ], this->vector[ 1 ] );
    }
    else if ( this->size == 1 ) {
        return std::abs( this->vector[ 0 ] );
    }
    else if ( !this->size ) {
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

    for ( int i = 0; i < t_vector.size - 1; ++i ) {
        t_ostream << t_vector.vector[ i ] << ", ";
    }

    t_ostream << t_vector.vector[ t_vector.size - 1 ] << ')';

    return t_ostream;
}

std::istream &operator>>( std::istream &t_istream, Vector &t_vector )
{
    delete[] t_vector.vector;

    // First argument is the size of vector
    t_istream >> t_vector.size;

    if ( t_vector.size > 0 ) {
        t_vector.vector = new double[ t_vector.size ];

        for ( int i = 0; i < t_vector.size; ++i ) {
            t_istream >> t_vector.vector[ i ];

            // Check for bad input
            if ( t_istream.bad() ) {
                std::cerr
                    << "Error while creating vector. Exit."
                    << std::endl;
                std::exit( 1 );
            }
            else if ( t_istream.fail() ) {
                // t_vector.vector[ i ] = 0;
                t_istream.clear();
                t_istream.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    else {
        std::cerr
            << "Vector size must be greater than 0. Exit."
            << std::endl;
        std::exit( 1 );
    }

    return t_istream;
}

int Vector::get_size() const
{
    return this->size;
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

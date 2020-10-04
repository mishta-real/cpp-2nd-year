#include "vector.hpp"

#include <cstdlib> // std::exit()
#include <cmath> // std::hypot(), std::sqrt(), std::pow()

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
        std::cerr << "Negative vector size is given while instantiation. Exit.";
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
        std::cerr << "Can not get element at negative index. Exit.";
        std::exit( 1 );
    }
    else {
        std::cerr << "The index is out of bounds. Exit.";
        std::exit( 1 );
    }
}

double &Vector::operator[]( const int index )
{
    if ( -1 < index && index < this->size ) {
        return this->vector[ index ];
    }
    else if ( index < 0 ) {
        std::cerr << "Can not get element at negative index. Exit.";
        std::exit( 1 );
    }
    else {
        std::cerr << "The index is out of bounds. Exit.";
        std::exit( 1 );
    }
}

Vector Vector::operator+( const Vector &t_vector ) const
{
    Vector vector_new = *this;

    if ( vector_new.size == t_vector.size ) {
        for ( int i = 0; i < vector_new.size; ++i ) {
            vector_new.vector[ i ] += t_vector.vector[ i ];
        }
    }
    else {
        std::cerr << "Can not sum two vectors with different sizes. Exit." << std::endl;
        std::exit ( 1 );
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

    if ( this->size == t_vector.size ) {
        for ( int i = 0; i < this->size; ++i ) {
            scalar_product += this->vector[ i ] * t_vector.vector[ i ];
        }
    }
    else {
        std::cerr << "Can not multiply two vectors with different sizes. Exit." << std::endl;
        std::exit( 1 );
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
        return this->vector[ 0 ];
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
    t_vector.vector = new double[ t_vector.size ];

    for ( int i = 0; i < t_vector.size; ++i ) {
        t_istream >> t_vector.vector[ i ];
    }

    return t_istream;
}

int Vector::get_size() const
{
    return this->size;
}

double angle( const Vector v1, const Vector v2 )
{
    if ( v1.get_size() != v2.get_size() ) {
        std::cerr << "Can not find the angle: vectors have different sizes. Exit.";
        std::exit( 1 );
    }

    const int size = v1.get_size();

    // Calculating the nominator
    double nominator = 0;

    for ( int i = 0; i < size; ++i ) {
        nominator += v1[ i ] * v2[ i ];
    }

    // Calculating the denominator
    double denominator = 1;
    double temp = 0;

    for ( int i = 0; i < size; ++i ) {
        temp += std::pow( v1[ i ], 2 );
    }

    denominator *= std::sqrt( temp );
    temp = 0;

    for ( int i = 0; i < size; ++i ) {
        temp += std::pow( v2[ i ], 2 );
    }

    denominator *= std::sqrt( temp );

    if ( denominator ) {
        // The angle:
        return std::acos( nominator / denominator );
    }
    else {
        // Null denominator means both vectors are 0
        return 0;
    }
}

} // namespace Vector

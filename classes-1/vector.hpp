#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream> // std::ostream, std::istream

namespace Vector {

class Vector {
public:
    Vector( const int t_size=1 );
    Vector( const Vector &t_vector );
    ~Vector();

    Vector &operator=( const Vector &t_vector );
    double &operator[]( const int index );
    double &operator[]( const int index ) const;
    Vector operator+( const Vector &t_vector ) const;
    Vector operator*( const double t_mul ) const;
    double operator*( const Vector &t_vector ) const;

    double length() const;

    bool operator>( const Vector &t_vector ) const;
    bool operator<( const Vector &t_vector ) const;
    bool operator==( const Vector &t_vector ) const;
    bool operator!=( const Vector &t_vector ) const;

    friend std::ostream &operator<<(
        std::ostream &t_ostream,
        const Vector &t_vector
    );

    friend std::istream &operator>>(
        std::istream &t_istream,
        Vector &t_vector
    );

    int get_size() const;

private:
    double *vector;
    int size;
}; // class Vector

double angle( const Vector v1, const Vector v2 );
} // namespace Vector

#endif

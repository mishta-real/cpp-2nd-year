#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"

#include <iostream> // std::ostream, std::istream

namespace Matrix {

class Matrix {
public:
    Matrix( const int t_rows=1, const int t_cols=1 );
    Matrix( const Matrix &t_matrix );
    ~Matrix();

    Matrix &operator=( const Matrix &t_matrix );
    Matrix operator+( const Matrix &t_matrix ) const;
    Matrix operator-( const Matrix &t_matrix ) const;
    Matrix operator*( const Matrix &t_matrix ) const;
    Matrix operator*( const double t_mul ) const;

    friend Matrix operator*(
        const Matrix &t_matrix,
        const Vector::Vector &t_vector
    );

    friend std::ostream &operator<<(
        std::ostream &t_ostream,
        const Matrix &t_matrix
    );

    friend std::istream &operator>>(
        std::istream &t_istream,
        Matrix &t_matrix
    );

private:
    double **m_matrix;
    int m_rows;
    int m_cols;
}; // class Matrix

} // namespace Matrix

#endif

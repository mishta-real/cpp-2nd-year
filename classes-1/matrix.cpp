#include "matrix.hpp"

#include <iomanip> // std::setw()
#include <iostream> // std::istream, std::ostream
#include <limits>

namespace Matrix {

Matrix::Matrix( const int t_rows, const int t_cols )
{
    if ( t_rows > 0 && t_cols > 0 ) {
        this->m_matrix = new double*[ t_rows ];
        this->m_rows = t_rows;
        this->m_cols = t_cols;

        for ( int i = 0; i < this->m_rows; ++i ) {
            this->m_matrix[ i ] = new double[ t_cols ];

            for ( int j = 0; j < this->m_cols; ++j ) {
                this->m_matrix[ i ][ j ] = 0;
            }
        }
    }
    else if ( t_rows < 1 && t_cols < 1 ) {
        std::cerr << "Bad matrix dimensions were given. Exit." << std::endl;
        std::exit( 1 );
    }
    else if ( t_rows < 1 && t_cols > 0 ) {
        std::cerr << "Bad number of rows was given. Exit." << std::endl;
        std::exit( 1 );
    }
    else {
        std::cerr << "Bad number of columns was given. Exit." << std::endl;
        std::exit( 1 );
    }
}

Matrix::Matrix( const Matrix &t_matrix )
{
    this->m_matrix = new double*[ t_matrix.m_rows ];
    this->m_rows = t_matrix.m_rows;
    this->m_cols = t_matrix.m_cols;

    for ( int i = 0; i < this->m_rows; ++i ) {
        this->m_matrix[ i ] = new double[ this->m_cols ];

        for ( int j = 0; j < this->m_cols; ++j ) {
            this->m_matrix[ i ][ j ] = t_matrix.m_matrix[ i ][ j ];
        }
    }
}

Matrix &Matrix::operator=( const Matrix &t_matrix )
{
    if ( this != &t_matrix ) {

        if ( this->m_rows != t_matrix.m_rows ||
            this->m_cols != t_matrix.m_cols )
        {
            for ( int i = 0; i < this->m_rows; ++i ) {
                delete[] this->m_matrix[ i ];
            }
            delete[] this->m_matrix;
        }

        this->m_matrix = new double*[ t_matrix.m_rows ];
        this->m_rows = t_matrix.m_rows;
        this->m_cols = t_matrix.m_cols;

        for ( int i = 0; i < this->m_rows; ++i ) {
            for ( int j = 0; j < this->m_cols; ++j ) {
                this->m_matrix[ i ][ j ] = t_matrix.m_matrix[ i ][ j ];
            }
        }
    }

    return *this;
}

Matrix::~Matrix()
{
    for ( int i = 0; i < this->m_rows; ++i ) {
        delete[] this->m_matrix[ i ];
        this->m_matrix[ i ] = nullptr;
    }

    delete[] this->m_matrix;
    this->m_matrix = nullptr;
}

// =============== Arithmetical operators ===============

Matrix Matrix::operator+( const Matrix &t_matrix ) const
{
    if ( this->m_rows == t_matrix.m_rows &&
        this->m_cols == t_matrix.m_cols )
    {
        Matrix matrix_new = *this;

        for ( int i = 0; i < matrix_new.m_rows; ++i ) {
            for ( int j = 0; j < matrix_new.m_cols; ++j ) {
                matrix_new.m_matrix[ i ][ j ] += t_matrix.m_matrix[ i ][ j ];
            }
        }

        return matrix_new;
    }
    else {
        std::cerr
            << "Can not add two matrices with different dimensions. Exit."
            << std::endl;
        std::exit( 1 );
    }
}

Matrix Matrix::operator-( const Matrix &t_matrix ) const
{
    if ( this->m_rows == t_matrix.m_rows &&
        this->m_cols == t_matrix.m_cols )
    {
        Matrix matrix_new = *this;

        for ( int i = 0; i < matrix_new.m_rows; ++i ) {
            for ( int j = 0; j < matrix_new.m_cols; ++j ) {
                matrix_new.m_matrix[ i ][ j ] -= t_matrix.m_matrix[ i ][ j ];
            }
        }

        return matrix_new;
    }
    else {
        std::cerr
            << "Can not substract two matrices with different dimensions. Exit."
            << std::endl;
        std::exit( 1 );
    }
}

Matrix Matrix::operator*( const Matrix &t_matrix ) const
{
    if ( this->m_cols == t_matrix.m_rows ) {
        Matrix matrix_new( this->m_rows, t_matrix.m_cols );

        for ( int i = 0; i < this->m_rows; ++i ) {
            for ( int j = 0; j < t_matrix.m_cols; ++j ) {
                for ( int k = 0; k < this->m_cols; ++k ) {
                    matrix_new.m_matrix[ i ][ j ] +=
                        this->m_matrix[ i ][ k ] * t_matrix.m_matrix[ k ][ j ];
                }
            }
        }

        return matrix_new;
    }
    else {
        std::cerr
            << "Can not multiply two matrices: bad dimensions. Exit."
            << std::endl;
        std::exit( 1 );
    }
}

Matrix Matrix::operator*( const double t_mul ) const
{
    Matrix matrix_new = *this;

    for ( int i = 0; i < this->m_rows; ++i ) {
        for ( int j = 0; j < this->m_cols; ++j ) {
            matrix_new.m_matrix[ i ][ j ] *= t_mul;
        }
    }

    return matrix_new;
}

Matrix operator*(
    const Matrix &t_matrix,
    const Vector::Vector &t_vector
) {
    if ( t_matrix.m_cols > 1 && t_matrix.m_cols == t_vector.get_size() ) {
        Matrix matrix_new( t_matrix.m_rows, 1 );

        for ( int i = 0; i < t_matrix.m_rows; ++i ) {
            for ( int j = 0; j < t_matrix.m_cols; ++j ) {
                matrix_new.m_matrix[ i ][ 0 ] +=
                    t_matrix.m_matrix[ i ][ j ] * t_vector[ j ];
            }
        }

        return matrix_new;
    }
    else if ( t_matrix.m_cols == 1 && t_vector.get_size() == t_matrix.m_rows ) {
        Matrix matrix_new( t_matrix.m_rows, t_matrix.m_rows );

        for ( int i = 0; i < t_matrix.m_rows; ++i ) {
            for ( int j = 0; j < t_vector.get_size(); ++j ) {
                for ( int k = 0; k < t_matrix.m_cols; ++k ) {
                    matrix_new.m_matrix[ i ][ j ] +=
                        t_matrix.m_matrix[ i ][ k ] * t_vector[ k ];
                }
            }
        }

        return matrix_new;
    }
    else {
        std::cerr
            << "Can not multiply matrix and vector: incompatible dimensions. Exit."
            << std::endl;
        std::exit( 1 );
    }
}

std::ostream &operator<<(
    std::ostream &t_ostream,
    const Matrix &t_matrix
) {
    // Beautified output

    // The number with the largest absolute value (space before values):
    unsigned max_abs = 0;

    for ( int i = 0; i < t_matrix.m_rows; ++i ) {
        for ( int j = 0; j < t_matrix.m_cols; ++j ) {
            if ( std::abs( t_matrix.m_matrix[ i ][ j ] ) > max_abs ) {
                max_abs = std::abs( t_matrix.m_matrix[ i ][ j ] );
            }
        }
    }

    size_t digit_count = 1;
    for ( ; max_abs > 0; ++digit_count ) {
        max_abs /= 10;
    }

    for ( int i = 0; i < t_matrix.m_rows; ++i ) {
        for ( int j = 0; j < t_matrix.m_cols; ++j ) {
            t_ostream
                << std::setw( digit_count )
                << t_matrix.m_matrix[ i ][ j ]
                << " ";
        }
        t_ostream << "\n";
    }

    return t_ostream;
}

std::istream &operator>>(
    std::istream &t_istream,
    Matrix &t_matrix
) {
    for ( int i = 0; i < t_matrix.m_rows; ++i ) {
        delete[] t_matrix.m_matrix[ i ];
    }

    delete[] t_matrix.m_matrix;

    // First argument is the amount of rows of matrix
    t_istream >> t_matrix.m_rows;
    // Seconds argument is the amount of columns of matrix
    t_istream >> t_matrix.m_cols;

    if ( t_matrix.m_rows > 0 && t_matrix.m_cols > 0 ) {

        // Creating empty matrix:
        t_matrix.m_matrix = new double*[ t_matrix.m_rows ];
        for ( int i = 0; i < t_matrix.m_rows; ++i ) {
            t_matrix.m_matrix[ i ] = new double[ t_matrix.m_cols ];
        }

        // Filling created matrix with values:
        for ( int i = 0; i < t_matrix.m_rows; ++i ) {
            for ( int j = 0; j < t_matrix.m_cols; ++j ) {

                t_istream >> t_matrix.m_matrix[ i ][ j ];

                // Validating the input
                if ( t_istream.bad() ) {
                    std::cerr
                        << "Error while creating matrix. Exit."
                        << std::endl;
                    std::exit( 1 );
                }
                else if ( t_istream.fail() ) {
                    std::cout << "First bad input replaced with 0. Everything past ignored.\nm2: ";
                    t_istream.clear();
                    t_istream.ignore(
                        std::numeric_limits< std::streamsize >::max(),
                        '\n'
                    );
                }
            }
        }

        return t_istream;
    }
    else { // t_matrix.m_rows <= 0 or t_matrix.m_cols <= 0
        std::cerr
            << "All matrix dimensions must be greater than 0. Exit."
            << std::endl;
        std::exit( 1 );
    }

}

}; // namespace Matrix

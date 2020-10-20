#include "complex.hpp"

#include <cstdlib> // std::exit()
#include <cmath> // std::hypot(), std::fabs()
#include <iostream> // std::ostream, std::istream

namespace Complex {

// =============== Constructors ===============

Complex::Complex()
{
    m_re = 0;
    m_im = 0;
}

Complex::Complex( const double t_re, const double t_im )
{
    m_re = t_re;
    m_im = t_im;
}

Complex::Complex( const Complex &t_complex )
{
    m_re = t_complex.m_re;
    m_im = t_complex.m_im;
}

// =============== Arithmetical operators ===============

double Complex::abs() const
{
    return std::hypot( m_re, m_im );
}

Complex &Complex::operator=( const Complex &t_complex )
{
    if ( this != &t_complex ) {
        m_re = t_complex.m_re;
        m_im = t_complex.m_im;
    }
    else {
        // Empty
    }

    return *this;
}

Complex Complex::operator+( const Complex &t_complex )
{
    return Complex(
        m_re + t_complex.m_re,
        m_im + t_complex.m_im
    );
}

Complex Complex::operator-( const Complex &t_complex )
{
    return Complex(
        m_re - t_complex.m_re,
        m_im - t_complex.m_im
    );
}

Complex Complex::operator*( const Complex &t_complex )
{
    return Complex(
        m_re * t_complex.m_re - m_im * t_complex.m_im,
        m_re * t_complex.m_im + m_im * t_complex.m_re
    );
}

Complex Complex::operator/( const Complex &t_complex )
{
    const double denominator {
        std::pow( t_complex.m_re, 2.0 ) +
        std::pow( t_complex.m_im, 2.0 )
    };

    if ( denominator ) {
        return Complex(
            (m_re * t_complex.m_re + m_im * t_complex.m_im) / denominator,
            (m_im * t_complex.m_re - m_re * t_complex.m_im) / denominator
        );
    }
    else {
        std::cerr << "Zero division attempt. Exit." << std::endl;
        std::exit( 1 );
    }
}

// =============== Relational operators ===============

bool Complex::operator!() const
{
    return !(m_re || m_im);
}

bool Complex::operator>( const Complex &t_complex ) const
{
    return abs() > t_complex.abs();
}

bool Complex::operator<( const Complex &t_complex ) const
{
    return abs() < t_complex.abs();
}

bool Complex::operator>=( const Complex &t_complex ) const
{
    return abs() >= t_complex.abs();
}

bool Complex::operator<=( const Complex &t_complex ) const
{
    return abs() <= t_complex.abs();
}

bool Complex::operator==( const Complex &t_complex ) const
{
    return abs() == t_complex.abs();
}

bool Complex::operator!=( const Complex &t_complex ) const
{
    return abs() != t_complex.abs();
}

// =============== Input/output operators ===============

std::ostream &operator<<( std::ostream &t_ostream, const Complex &t_complex )
{
    if ( t_complex.m_re ) {
        if ( t_complex.m_im > 0.0 && t_complex.m_im != 1.0 ) {
            t_ostream << t_complex.m_re << " + " << t_complex.m_im << "i";
        }
        else if ( t_complex.m_im == 1.0 ) {
            t_ostream << t_complex.m_re << " + i";
        }
        else if ( t_complex.m_im == 0.0 ) {
            t_ostream << t_complex.m_re;
        }
        else if ( t_complex.m_im == -1.0 ) {
            t_ostream << t_complex.m_re << " - i";
        }
        else {
            t_ostream << t_complex.m_re << " - " << -t_complex.m_im << "i";
        }
    }
    else {
        if ( t_complex.m_im != 0.0 && std::fabs( t_complex.m_im ) != 1.0 ) {
            t_ostream << t_complex.m_im << "i";
        }
        else if ( t_complex.m_im == 1.0 ) {
            t_ostream << "i";
        }
        else if ( t_complex.m_im == -1.0 ) {
            t_ostream << "-i";
        }
        else {
            t_ostream << "0";
        }
    }

    return t_ostream;
}

std::istream &operator>>( std::istream &t_istream, Complex &t_complex )
{
    t_istream >> t_complex.m_re;
    t_istream >> t_complex.m_im;

    return t_istream;
}

} // namespace Complex

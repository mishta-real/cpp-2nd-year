#include "complex.hpp"

#include <cmath> // std::hypot


namespace Complex {

// =============== Constructors ===============

Complex::Complex()
{
    // Empty
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

// =============== Operators ===============

inline double Complex::abs() const
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
    return Complex( m_re + t_complex.m_re, m_im + t_complex.m_im );
}

Complex Complex::operator-( const Complex &t_complex )
{
    return Complex( m_re - t_complex.m_re, m_im - t_complex.m_im );
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
        std::pow( t_complex.m_re, 2.0 ) + std::pow( t_complex.m_im, 2.0 )
    };

    return Complex(
        (m_re * t_complex.m_re + m_im * t_complex.m_im) / denominator,
        (m_im * t_complex.m_re - m_re * t_complex.m_im) / denominator
    );
}

} // namespace Complex

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

namespace Complex {

class Complex {
public:
    Complex();
    Complex( const double t_re, const double t_im );
    Complex( const Complex &t_complex );

    double abs() const;

    Complex &operator=( const Complex &t_complex );
    Complex operator+( const Complex &t_complex );
    Complex operator-( const Complex &t_complex );
    Complex operator*( const Complex &t_complex );
    Complex operator/( const Complex &t_complex );

    bool operator!() const;
    bool operator>( const Complex &t_complex ) const;
    bool operator<( const Complex &t_complex ) const;
    bool operator>=( const Complex &t_complex ) const;
    bool operator<=( const Complex &t_complex ) const;
    bool operator==( const Complex &t_complex ) const;
    bool operator!=( const Complex &t_complex ) const;

    friend std::ostream &operator<<(
        std::ostream &t_ostream,
        const Complex &t_complex
    );

    friend std::istream &operator>>(
        std::istream &t_istream,
        Complex &t_complex
    );

private:
    double m_re;
    double m_im;
}; // class Complex

} // namespace Complex

#endif

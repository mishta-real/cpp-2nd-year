#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

namespace Complex {

class Complex {
public:
    Complex();
    Complex( const double t_re=0.0, const double t_im=0.0 );
    Complex( const Complex &t_complex );

    inline double abs() const;

    Complex &operator=( const Complex &t_complex );
    Complex operator+( const Complex &t_complex );
    Complex operator-( const Complex &t_complex );
    Complex operator*( const Complex &t_complex );
    Complex operator/( const Complex &t_complex );

    inline bool operator>( const Complex &t_complex ) const;
    inline bool operator<( const Complex &t_complex ) const;
    inline bool operator==( const Complex &t_complex ) const;
    inline bool operator!=( const Complex &t_complex ) const;

    friend std::ostream &operator<<(
        std::ostream& t_ostream,
        const Complex &t_complex
    );

    friend std::istream &operator>>(
        std::istream &t_istream,
        Complex &t_complex
    );

private:
    double m_re{ 0 };
    double m_im{ 0 };
}; // class Complex

} // namespace Complex

#endif

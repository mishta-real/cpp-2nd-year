#include "complex.hpp"

#include <iostream>

void test_complex()
{
    std::cout << "c1 >> ";
    Complex::Complex c1;
    std::cin >> c1;

    std::cout << "c2 >> ";
    Complex::Complex c2;
    std::cin >> c2;

    std::cout << std::endl;

    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n";

    std::cout << std::endl;

    std::cout << "c1 + c2 = " << c1 + c2 << "\n";
    std::cout << "c1 - c2 = " << c1 - c2 << "\n";
    std::cout << "c1 * c2 = "  << c1 * c2 << "\n";
    std::cout << "c1 / c2 = "  << c1 / c2 << "\n";

    std::cout << std::endl;

    std::cout << "|c1| = " << c1.abs() << "\n";
    std::cout << "|c2| = " << c2.abs() << "\n";
    c1 > c2 ? std::cout << "c1 > c2 ? yes\n" : std::cout << "c1 > c2 ? no\n";
    c1 < c2 ? std::cout << "c1 < c2 ? yes\n" : std::cout << "c1 > c2 ? no\n";
    c1 == c2 ? std::cout << "c1 = c2 ? yes\n" : std::cout << "c1 = c2 ? no\n";
    c1 != c2 ? std::cout << "c1 != c2 ? yes\n" : std::cout << "c1 != c2 ? no";
}

int main()
{
    test_complex();
    return 0;
}

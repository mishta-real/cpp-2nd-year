#include "complex.hpp"
#include "vector.hpp"

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
    c1 == c2 ? std::cout << "c1 == c2 ? yes\n" : std::cout << "c1 == c2 ? no\n";
    c1 != c2 ? std::cout << "c1 != c2 ? yes\n" : std::cout << "c1 != c2 ? no";
}

void test_vector()
{
    std::cout << "v1 (1st argument - size): ";
    Vector::Vector v1;
    std::cin >> v1;

    std::cout << "v2 (1st argument - size): ";
    Vector::Vector v2;
    std::cin >> v2;

    std::cout << std::endl;

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";

    std::cout << std::endl;

    std::cout << "v1 + v2 = " << v1 + v2 << "\n";
    std::cout << "v1 * 15 = " << v1 * 15 << "\n";
    std::cout << "v2 * 15 = " << v2 * 15 << "\n";
    std::cout << "v1 * v2 = " << v1 * v2 << "\n";

    std::cout << std::endl;

    std::cout << "|v1| = " << v1.length() << "\n";
    std::cout << "|v2| = " << v2.length() << "\n";
    v1 > v2 ? std::cout << "v1 > v2 ? yes\n" : std::cout << "v1 > v2 ? no\n";
    v1 < v2 ? std::cout << "v1 < v2 ? yes\n" : std::cout << "v1 > v2 ? no\n";
    v1 == v2 ? std::cout << "v1 == v2 ? yes\n" : std::cout << "v1 == v2 ? no\n";
    v1 != v2 ? std::cout << "v1 != v2 ? yes\n" : std::cout << "v1 != v2 ? no\n";

    std::cout << std::endl;

    std::cout << "angle: " << Vector::angle( v1, v2 );
}

int main()
{
    // test_complex();
    // std::cout << std::endl;

    test_vector();
    std::cout << std::endl;

    return 0;
}

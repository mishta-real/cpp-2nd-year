#include "complex.hpp"
#include "vector.hpp"
#include "matrix.hpp"

#include <iostream>
#include <limits>
#include <string>

namespace Test {

enum Tests {
    Complex = 1,
    Vector = 2,
    Matrix = 3
};

void test_complex()
{
    const std::string menu_complex =
        "\n1. Test assignment operations"
        "\n2. Add two complex numbers" \
        "\n3. Substract two complex numbers" \
        "\n4. Multiply two complex numbers" \
        "\n5. Divide two complex numbers" \
        "\n6. Get length of two complex numbers" \
        "\n7. Compare two complex numbers" \
        "\n0. Return\n";

    int choice = 0;
    do {
        std::cout << menu_complex;

        std::cout << "Your choice: ";
        std::cin >> choice;

        if ( choice == 1 || choice == 2 || choice == 3 ||
            choice == 4 || choice == 5 || choice == 6 || choice == 7 )
        {
            std::cout << "\nc1 >> ";
            Complex::Complex c1;
            std::cin >> c1;

            std::cout << "c2 >> ";
            Complex::Complex c2;
            std::cin >> c2;

            std::cout << std::endl;

            std::cout << "c1 = " << c1 << "\n";
            std::cout << "c2 = " << c2 << "\n";

            std::cout << std::endl;

            if ( choice == 1 ) {
                Complex::Complex c3( c1 );
                std::cout << "c3( c1 ) = " << c3 << "\n";

                Complex::Complex c4 = c2;
                std::cout << "c4 = c2 = " << c4 << "\n";
            }
            else if ( choice == 2 ) {
                std::cout << "c1 + c2 = " << c1 + c2 << "\n\n";
            }
            else if ( choice == 3 ) {
                std::cout << "c1 - c2 = " << c1 - c2 << "\n\n";
            }
            else if ( choice == 4 ) {
                std::cout << "c1 * c2 = "  << c1 * c2 << "\n\n";
            }
            else if ( choice == 5 ) {
                std::cout << "c1 / c2 = "  << c1 / c2 << "\n\n";
            }
            else if ( choice == 6 ) {
                std::cout << "|c1| = " << c1.abs() << "\n";
                std::cout << "|c2| = " << c2.abs() << "\n\n";
            }
            else if ( choice == 7 ) {
                c1 > c2 ?
                    std::cout << "c1 > c2 ? yes\n" :
                    std::cout << "c1 > c2 ? no\n";
                c1 < c2 ?
                    std::cout << "c1 < c2 ? yes\n" :
                    std::cout << "c1 < c2 ? no\n";
                c1 >= c2 ?
                    std::cout << "c1 ≥ c2 ? yes\n" :
                    std::cout << "c1 ≥ c2 ? no\n";
                c1 <= c2 ?
                    std::cout << "c1 ≤  c2 ? yes\n" :
                    std::cout << "c1 ≤ c2 ? no\n";
                c1 == c2 ?
                    std::cout << "c1 == c2 ? yes\n" :
                    std::cout << "c1 == c2 ? no\n";
                c1 != c2 ?
                    std::cout << "c1 ≠ c2 ? yes\n" :
                    std::cout << "c1 ≠ c2 ? no\n";
            }
        }
    } while ( choice == 1 || choice == 2 || choice == 3 ||
            choice == 4 || choice == 5 || choice == 6 ||
            choice == 7 );

    std::cout << std::endl;
}

void test_vector()
{
    const std::string menu_vector =
        "\n1. Test assignment operations"
        "\n2. Add two vectors" \
        "\n3. Multiply vectors by a number" \
        "\n4. Multiply two vectors" \
        "\n5. Get length of two vectors" \
        "\n6. Compare two vectors" \
        "\n7. Get the angle between two vectors" \
        "\n0. Return\n";

    int choice = 0;
    do {
        std::cout << menu_vector;

        std::cout << "Your choice: ";
        std::cin >> choice;

        if ( choice == 1 || choice == 2 || choice == 3 ||
            choice == 4 || choice == 5 || choice == 6 ||
            choice == 7 )
        {
            std::cout << "\nv1 (1st arg - size): ";
            Vector::Vector v1;
            std::cin >> v1;

            std::cout << "v2 (1st arg - size): ";
            Vector::Vector v2;
            std::cin >> v2;

            std::cout << std::endl;

            std::cout << "v1 = " << v1 << "\n";
            std::cout << "v2 = " << v2 << "\n\n";

            if ( choice == 1 ) {
                Vector::Vector v3( v1 );
                std::cout << "v3( v1 ): " << v3 << "\n";

                Vector::Vector v4 = v2;
                std::cout << "v4 = v2 = " << v4 << "\n";
            }
            else if ( choice == 2 ) {
                std::cout << "v1 + v2 = " << v1 + v2 << "\n";
            }
            else if ( choice == 3 ) {
                std::cout << "Enter the number: ";
                double number = 0;
                std::cin >> number;

                if ( !std::cin.fail() ) {
                    std::cout << "\nv1 * " << number << " = " << v1 * number << "\n";
                    std::cout << "v2 * " << number << " = " << v2 * number;
                }
                else {
                    std::cout << "Bad input.";
                    std::cin.clear();
                    std::cin.ignore(
                        std::numeric_limits< std::streamsize >::max(),
                        '\n'
                    );
                }
                std::cout << "\n";
            }
            else if ( choice == 4 ) {
                std::cout << "v1 * v2 = "  << v1 * v2 << "\n";
            }
            else if ( choice == 5 ) {
                std::cout << "|v1| = " << v1.length() << "\n";
                std::cout << "|v2| = " << v2.length() << "\n";
            }
            else if ( choice == 6 ) {
                v1 > v2 ?
                    std::cout << "v1 > v2 ? yes\n" :
                    std::cout << "v1 > v2 ? no\n";
                v1 < v2 ?
                    std::cout << "v1 < v2 ? yes\n" :
                    std::cout << "v1 > v2 ? no\n";
                v1 >= v2 ?
                    std::cout << "v1 ≥ v2 ? yes\n" :
                    std::cout << "v1 ≥ v2 ? no\n";
                v1 <= v2 ?
                    std::cout << "v1 ≤ v2 ? yes\n" :
                    std::cout << "v1 ≤ v2 ? no\n";
                v1 == v2 ?
                    std::cout << "v1 == v2 ? yes\n" :
                    std::cout << "v1 == v2 ? no\n";
                v1 != v2 ?
                    std::cout << "v1 ≠ v2 ? yes\n" :
                    std::cout << "v1 ≠ v2 ? no\n";
            }
            else if ( choice == 7 ) {
                std::cout << "angle: " << Vector::angle( v1, v2 ) << "\n";
            }
        }
    }  while ( choice == 1 || choice == 2 || choice == 3 ||
            choice == 4 || choice == 5 || choice == 6 ||
            choice == 7 );

    std::cout << std::endl;
}

void test_matrix()
{
    const std::string menu_matrix =
        "\n1. Test assisgnment operations" \
        "\n2. Add two matrices" \
        "\n3. Substract two matrices" \
        "\n4. Multiply two matrices" \
        "\n5. Multiply two matrices and a number" \
        "\n6. Multiply two matrices and vector" \
        "\n0. Return\n";

    int choice = 0;
    do {
        std::cout << menu_matrix;

        std::cout << "Your choice: ";
        std::cin >> choice;

        if ( choice == 1 || choice == 2 || choice == 3 ||
            choice == 4 || choice == 5 || choice == 6 )
        {
            std::cout << "\nm1 (1st arg - rows amount, 2nd arg - columns amount): ";
            Matrix::Matrix m1;
            std::cin >> m1;

            std::cout << "m2 (1st arg - rows amount, 2nd arg - columns amount): ";
            Matrix::Matrix m2;
            std::cin >> m2;

            std::cout << "\nm1:\n" << m1 << "\n";
            std::cout << "m2:\n" << m2 << "\n";

            if ( choice == 1 ) {
                Matrix::Matrix m3( m1 );
                std::cout << "m3( m1 ):\n" << m3 << "\n";

                Matrix::Matrix m4 = m2;
                std::cout << "m4 = m2:\n" << m4 << "\n";
            }
            else if ( choice == 2 ) {
                std::cout << "m1 + m2:\n" << m1 + m2 << "\n";
            }
            else if ( choice == 3 ) {
                std::cout << "m1 - m2:\n" << m1 - m2 << "\n";
             }
            else if ( choice == 4 ) {
                std::cout << "m1 * m2:\n" << m1 * m2 << "\n";
            }
            else if ( choice == 5 ) {
                std::cout << "Enter the number: ";
                double number = 0;
                std::cin >> number;

                if ( !std::cin.fail() ) {
                    std::cout << "m1 * " << number << ":\n" << m1 * number;
                    std::cout << "\nm2 * " << number << ":\n" << m2 * number;
                }
                else {
                    std::cout << "Bad input.";
                    std::cin.clear();
                    std::cin.ignore(
                        std::numeric_limits< std::streamsize >::max(),
                        '\n'
                    );
                }
                std::cout << "\n";
            }
            else if ( choice == 6 ) {
                std::cout << "v (1st arg - size): ";
                Vector::Vector v;
                std::cin >> v;
                std::cout << "v = " << v << "\n";

                std::cout << std::endl;

                std::cout << "m1 * v:\n" << m1 * v << "\n";
                std::cout << "m2 * v:\n" << m2 * v << "\n";
            }
        }
    }  while ( choice == 1 || choice == 2 || choice == 3 ||
            choice == 4 || choice == 5 || choice == 6 );

    std::cout << std::endl;
}

} // namespace Test

int ask_choice()
{
    std::cout << "Your choice: ";
    int choice = 0;
    std::cin >> choice;

    return choice;
}

void menu()
{
    int choice = 0;
    do {
        std::cout
            << "1. Test class \'Complex\'"
            << "\n2. Test class \'Vector\'"
            << "\n3. Test class \'Matrix\'"
            << "\n0. Exit\n";

        switch ( choice = ask_choice() ) {
        case Test::Complex:
            Test::test_complex();
            break;
        case Test::Vector:
            Test::test_vector();
            break;
        case Test::Matrix:
            Test::test_matrix();
            break;
        }
    } while ( choice == Test::Complex ||
            choice == Test::Vector ||
            choice == Test::Matrix );
}

int main()
{
    menu();
    return 0;
}

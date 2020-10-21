#include "complex.hpp"
#include "set.hpp"
#include "vector.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

namespace Test {

void open_file( std::ifstream &file, const std::string &filename )
{
    try {
        file.open( filename );
        if ( !file.is_open() ) {
            throw "can not find file";
        }
    } catch ( const char *exception ) {
        std::cerr
            << "Error while opening file "
            << filename
            << ": "
            << exception
            << ". Exit"
            << std::endl;

        std::exit( 1 );
    }
}

void parse_file( std::ifstream &file, Set::Set<int> &t_set )
{
    for ( std::string buffer; file; ) {
        std::getline( file, buffer );
        if ( !buffer.empty() ) {
            t_set.insert( std::stoi( buffer ) );
        }
    }
}

void test_vector()
{
    Vector::Vector<int> v_int = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout
        << "Integer vector v_int = " << v_int
        << "\nLength (geometrical): " << v_int.length() << "\n\n";

    Vector::Vector<double> v_double = { 1.24, 26.21, 63.02, 1222.0009 };
    std::cout
        << "Double vector v_double = " << v_double
        << "\nLength (geometrical): " << v_double.length() << "\n\n";

    Vector::Vector<Complex::Complex> v_complex = {
        Complex::Complex( 2, 3 ),
        Complex::Complex( -2, 24 ),
        Complex::Complex( .21, -66 ),
        Complex::Complex( -.652, .126 )
    };
    std::cout
        << "Complex vector v_complex = " << v_complex
        << "\nLength (number of coordinates): " << v_complex.length() << '\n';

    std::cout << "\n------------------------------------------------------\n";

    std::cout << std::endl;
}


void test_set()
{
    /* Task 1 */
    std::ifstream m1_data;
    Test::open_file( m1_data, "m1.dat" );
    Set::Set<int> m1;
    Test::parse_file( m1_data, m1 );
    m1.sort();
    std::cout << "M_1 = " << m1 << '\n';
    std::cout << "Size of m1: " << m1.size() << "\n\n";

    std::ifstream m2_data( "m2.dat" );
    Set::Set<int> m2;
    Test::parse_file( m2_data, m2 );
    m2.sort();
    std::cout << "M_2 = " << m2 << '\n';
    std::cout << "Size of m2: " << m2.size() << "\n\n";

    std::ifstream m3_data( "m3.dat" );
    Set::Set<int> m3;
    Test::parse_file( m3_data, m3 );
    m3.sort();
    std::cout << "M_3 = " << m3 << '\n';
    std::cout << "Size of m3: " << m3.size() << "\n\n";

    /* Task 2 */
    if ( m1.is_equal( m2 ) ) {
        std::cout << "M_1 is equal to M_2\n\n";
    }
    else if ( m1.is_proper_subset( m2 ) ) {
        std::cout << "M_1 is a proper subset of M_2\n\n";
    }
    else if ( m2.is_proper_subset( m1 ) ) {
        std::cout << "M_2 is a proper subset of M_1\n\n";
    }
    else if ( m1.intersects( m2 ) ) {
        std::cout << "M_1 and M_2 only do intersect\n\n";
    }
    else {
        std::cout << "M_1 and M_2 do not intersect\n\n";
    }

    /* Task 3 */
    std::cout << "Type value to insert into M_1: ";
    m1.insert();
    std::cout << "M_1 = " << m1 << "\n\n";

    /* Task 4 */
    std::cout << "Type value to remove from M_2: ";
    m2.remove();
    std::cout << "M_2 = " << m2 << "\n\n";

    /* Additional task */
    std::cout << "Intersection of M_1 and M_2:\n";
    Set::Set<int> m4 = m1.intersect( m2 );
    std::cout << "M_4 = " << m4 << "\n\n";

    /* Task 5 */
    std::cout << "Union of M_2 and M_3:\n";
    Set::Set<int> m5 = m2 + m3;
    std::cout << "M_5 = " << m5 << "\n\n";

    /* Task 6 */
    std::cout << "The set can consist only of integers not divisable by 3:\n";
    const int list[5] = { 4251, 6742, 9862, 1248, 2550 };
    for ( unsigned i = 0; i < 5; ++i ) {
        if ( Set::is_type_valid( list[ i ] ) ) {
            std::cout << list[ i ] << " can belong to this set\n";
        }
        else {
            std::cout << list[ i ] << " can not belong to this set\n";
        }
    }
    std::cout << std::endl;
}

} // namespace Test

int main()
{
    Test::test_vector();
    Test::test_set();
    return 0;
}

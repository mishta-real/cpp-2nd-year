#include "strings.hpp"
#include "vectors.hpp"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

namespace Util {

std::string get_string( const char *message )
{
    std::cin.clear();
    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

    std::cout << message;

    std::string buffer;
    std::getline( std::cin, buffer );

    return buffer;
}

void open_file(
        std::ifstream &t_file,
        const char *t_filename
) {
    try {
        t_file.open( t_filename );

        if ( !t_file.is_open() ) {
            throw "can not find file";
        }
    } catch ( const char *exception ) {
        std::cerr
            << "Error while opening file "
            << t_filename
            << ": "
            << exception
            << ". Exit"
            << std::endl;

        std::exit( 1 );
    }
}

void parse_file(
        std::ifstream &t_file,
        std::vector<int> &t_vector
) {
    for ( std::string buffer; t_file; ) {
        std::getline( t_file, buffer );

        if ( !buffer.empty() ) {
            t_vector.push_back( std::stoi( buffer ) );
        }
    }
}

void refresh_file(
        std::ifstream &t_file
) {
    t_file.clear();
    t_file.seekg( 0, t_file.beg );
}

} // namespace Util


namespace Test {

enum Tests {
    Strings = 1,
    Vectors = 2
};

void menu_strings()
{
    std::cout
        << "\n1. Check string for being palindrome"
        << "\n2. Validate bracket pairness"
        << "\n0. Exit\n";
}

void test_strings()
{
    int choice = 0;
    do {
        menu_strings();
        std::cout << "Your choice: ";
        std::cin >> choice;

        if ( choice == 1 ) {
            const std::string t_string = Util::get_string( "Enter string: " );

            if ( Strings::is_palindrome( t_string ) ) {
                std::cout
                    << '\'' << t_string << '\''
                    << " is palindrome.\n";
            }
            else {
                std::cout
                    << '\'' << t_string << '\''
                    << " is not palindrome.\n";
            }
            std::cout << std::endl;
        }
        else if ( choice == 2 ) {
            const std::string t_string = Util::get_string( "Enter string: " );

            if ( Strings::has_brackets( t_string ) ) {
                if ( Strings::brackets_valid( t_string ) ) {
                    std::cout
                        << '\'' << t_string << '\''
                        << " has valid brackets.\n";
                }
                else {
                    std::cout
                        << '\'' << t_string << '\''
                        << " does not have valid brackets.\n";
                }
            }
            else {
                std::cout
                    << '\'' << t_string << '\''
                    << " has no brackets.\n";
            }
            std::cout << std::endl;
        }
    } while ( choice == 1 || choice == 2 );
}

void menu_vectors()
{
    std::cout
        << "\n1. Count number N in a vector and get its indices"
        << "\n2. Count even numbers and get their indices & sum"
        << "\n3. Sort the vector"
        << "\n4. Swap vector edges"
        << "\n0. Exit\n";
}

void test_vectors()
{
    int choice = 0;
    do {
        menu_vectors();
        std::cout << "Your choice: ";
        std::cin >> choice;

        if ( choice == 1 ) {
            std::vector<int> t_vector;
            std::ifstream file;
            Util::open_file( file, "vector.dat" );
            Util::parse_file( file, t_vector );
            Util::refresh_file( file );

            std::cout << "\nVector: ";
            std::cout << '{';
            Vectors::print( t_vector );
            std::cout << '}';

            std::cout << "\nEnter number N: ";
            int n = 0;
            std::cin >> n;

            std::cout
                << "Amount of " << n << " in vector: "
                << Vectors::count_n( t_vector, n )
                << std::endl;

            std::cout << "Indices of " << n << ": ";
            std::cout << '{';
            Vectors::print( Vectors::indices_of_n( t_vector, n ) );
            std::cout << '}';
            std::cout << '\n';

            std::cout << std::endl;
        }
        else if ( choice == 2 ) {
            std::vector<int> t_vector;
            std::ifstream file;
            Util::open_file( file, "vector.dat" );
            Util::parse_file( file, t_vector );
            Util::refresh_file( file );

            std::cout << "\nVector: ";
            std::cout << '{';
            Vectors::print( t_vector );
            std::cout << '}';

            const size_t even_amount = Vectors::count_even( t_vector );
            std::cout
                << "\nAmount of even numbers: "
                << even_amount
                << std::endl;

            std::cout << "Indices of even numbers: ";
            std::cout << '{';
            Vectors::print( Vectors::indices_of_even( t_vector ) );
            std::cout << '}';
            std::cout << std::endl;

            if ( even_amount * 2 > t_vector.size() ) {
                std::cout
                    << "There are more even numbers than odd."
                    << "\nSum of even numbers: "
                    << Vectors::sum_even_of( t_vector );
            }
            else {
                even_amount * 2 < t_vector.size() ?
                    std::cout << "There are more odd numbers than even." :
                    std::cout << "Amounts of even and odd numbers are equal.";

                std::cout
                    << "\nSum of all numbers: "
                    << Vectors::sum_all_of( t_vector );
            }
            std::cout << '\n';

            std::cout << std::endl;
        }
        else if ( choice == 3 ) {
            std::vector<int> t_vector;
            std::ifstream file;
            Util::open_file( file, "vector.dat" );
            Util::parse_file( file, t_vector );
            Util::refresh_file( file );

            std::cout << "Initial vector: ";
            std::cout << '{';
            Vectors::print( t_vector );
            std::cout << '}';

            Vectors::sort( t_vector );
            std::cout << "\nSorted vector: ";
            std::cout << '{';
            Vectors::print( t_vector );
            std::cout << "}\n";

            std::cout << std::endl;
        }
        else if ( choice == 4 ) {
            std::vector<int> t_vector;
            std::ifstream file;
            Util::open_file( file, "vector.dat" );
            Util::parse_file( file, t_vector );
            Util::refresh_file( file );

            std::cout << "Initial vector: ";
            std::cout << '{';
            Vectors::print( t_vector );
            std::cout << "}\n";

            Vectors::swap_edges( t_vector );
            std::cout << "Modified vector: ";
            std::cout << '{';
            Vectors::print( t_vector );
            std::cout << "}\n";

            std::cout << std::endl;
        }
    } while ( choice == 1 || choice == 2 || choice == 3 || choice == 4 );
}

} // namespace Test

int main()
{
    int choice = 0;
    do {
        std::cout
            << "\n1. Task 1"
            << "\n2. Task 2"
            << "\n0. Exit\n";

        std::cout << "Your choice: ";
        std::cin >> choice;

        switch ( choice ) {
        case Test::Strings:
            Test::test_strings();
            break;

        case Test::Vectors:
            Test::test_vectors();
            break;
        }
    } while ( choice == Test::Strings || choice == Test::Vectors );

    return 0;
}

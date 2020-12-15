#ifndef TABLE_HPP
#define TABLE_HPP

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

class Table {
public:
    Table()
    {
        std::cout << "Table::Table()\n";

        m_size = new int;
        m_color = new char[ 10 ];
    }

    Table( int t_size, char* t_color )
    {
        std::cout << "Table::Table( int, char* )\n";

        if ( t_size > 0 ) {
            m_size = new int;
            *m_size = t_size;
        }
        else {
            std::cerr
                << "У стола размер больше нуля, введено: "
                << t_size
                << ". Выход."
                << std::endl;

            std::exit( 1 );
        }

        m_color = new char[ 10 ];
        strcpy( m_color, t_color );
    }

    Table( int t_size )
    {
        std::cout << "Table::Table( int )\n";

        if ( t_size > 0 ) {
            m_size = new int;
            *m_size = t_size;
        }
        else {
            std::cerr
                << "У стола размер больше нуля, введено: "
                << t_size
                << ". Выход."
                << std::endl;

            std::exit( 1 );
        }

        m_color = new char[ 10 ];
    }

    virtual ~Table()
    {
        std::cout << "Table::~Table()\n";

        delete m_size;
        delete[] m_color;
    }

    virtual void show()
    {
        std::cout
            << "Обычный стол:"
            << "\n\tразмер: " << *m_size
            << "\n\tцвет: " << m_color
            << std::endl;
    }

    virtual int calc_volume()
    {
        return std::pow( *m_size, 3 );
    }

private:
    int* m_size;
    char* m_color;
}; // class Table

#endif

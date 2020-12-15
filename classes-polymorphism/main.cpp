#include "table.hpp"
#include "comptable.hpp"
#include "roundtable.hpp"

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

const double get_table_cost( Table* table )
{
    return table->calc_volume() * 15;
    // 15 - стоимость единицы объёма
}

int main()
{
    std::cout << "ЧАСТЬ 1\n\n";

    Table* table = new Table( 10, "коричневый" );
    table->show();
    table->calc_volume();

    delete table;
    table = nullptr;

    std::cout << std::endl;

    CompTable* ctable = new CompTable( 10, "белый", 2, "ДСП" );
    ctable->show();
    ctable->calc_volume_ct();

    delete ctable;
    ctable = nullptr;

    std::cout << std::endl;

    RoundTable* rtable = new RoundTable( 12, "чёрный", 10 );
    rtable->show();
    rtable->calc_volume_rt();

    delete rtable;
    rtable = nullptr;

    std::cout << std::endl << "ЧАСТЬ 2\n\n";

    Table* random_table;

    std::cout
        << "Выберите стол:"
        << "\n1. Обычный стол"
        << "\n2. Компьютерный стол"
        << "\n3. Круглый стол"
        << "\nВыбор: ";

    int choice = 0;
    std::cin >> choice;

    if ( choice == 1 ) {
        std::cout << '\n';
        random_table = new Table( 10, "коричневый" );
    }
    else if ( choice == 2 ) {
        std::cout << '\n';
        random_table = new CompTable( 10, "белый", 10, "дерево" );
    }
    else if ( choice == 3 ) {
        std::cout << '\n';
        random_table = new RoundTable( 10, "черный", 15.5 );
    }
    else {
        return 0;
    }

    random_table->show();

    std::cout << "\nЦена стола: " << get_table_cost( random_table ) << std::endl;

    delete random_table;
    random_table = nullptr;

    return 0;
}

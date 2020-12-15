#include "circle.hpp"
#include "cylinder.hpp"
#include "figure.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"

#include <iostream>

// Специально не стал задавать высоту через std::cin
// По заданию это не нужно
constexpr double HEIGHT = 17.25;

// double cylinder_volume( IFigure* t_figure, const double t_height )
// {
//     return t_figure->calc_area() * t_height;
// }

int main()
{
    // Проверка чтобы изменение фигуры не изменяло цилиндр

    std::cout << "ДО ИЗМЕНЕНИЯ ФИГУРЫ:\n";

    Circle* test_circle = new Circle( 1 );
    Cylinder* test_cylinder = new Cylinder( test_circle, HEIGHT );

    test_circle->show();

    std::cout << '\n';

    test_cylinder->show();

    std::cout << "\nПОСЛЕ ИЗМЕНЕНИЯ ФИГУРЫ:\n";

    *test_circle = Circle( 12345 );

    test_circle->show();

    std::cout << '\n';

    test_cylinder->show();

    delete test_circle;
    test_circle = nullptr;

    delete test_cylinder;
    test_cylinder = nullptr;

    std::cout << "\n\n";

    // Основная прога
    IFigure* chosen_figure;

    std::cout
        << "Выберите фигуру:"
        << "\n1. Окружность"
        << "\n2. Прямоугольник"
        << "\n3. Параллелограмм"
        << "\nВыбор: ";

    int choice = 0;
    std::cin >> choice;

    if ( choice == 1 ) {
        std::cout << '\n';
        chosen_figure = new Circle( 12 );
    }
    else if ( choice == 2 ) {
        std::cout << '\n';
        chosen_figure = new Rectangle( 12, 5 );
    }
    else if ( choice == 3 ) {
        std::cout << '\n';
        chosen_figure = new Parallelogram( 15, 9, HEIGHT );
    }
    else {
        return 0;
    }

    chosen_figure->show();

    std::cout << '\n';

    Cylinder* cylinder = new Cylinder( chosen_figure, HEIGHT );

    cylinder->show();

    delete chosen_figure;
    chosen_figure = nullptr;

    delete cylinder;
    cylinder = nullptr;

    return 0;
}

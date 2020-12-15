#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include "figure.hpp"

#include <iostream>

class Cylinder {
public:
    Cylinder()
    {
        m_base = nullptr;

        m_height = new double;
        *m_height = 0;
    }

    Cylinder( IFigure* t_base, const double t_height )
    {
        m_base = t_base->copy();

        m_height = new double;
        *m_height = t_height;
    }

    Cylinder operator=( const Cylinder& t_cylinder )
    {
        if ( this != &t_cylinder ) {
            m_base = t_cylinder.m_base->copy();

            m_height = new double;
            *m_height = *(t_cylinder.m_height);
        }

        return *this;
    }

    Cylinder( const Cylinder& t_cylinder )
    {
        m_base = t_cylinder.m_base->copy();

        m_height = new double;
        *m_height = *(t_cylinder.m_height);
    }

    ~Cylinder()
    {
        delete m_base;
        delete m_height;
    }

    double calc_area()
    {
        return 2 * m_base->calc_area() + (*m_height) * m_base->calc_perimeter();
    }

    double calc_volume()
    {
        return m_base->calc_area() * (*m_height);
    }

    void show()
    {
        std::cout
            << "ЦИЛИНДР:"
            << "\nПлощадь:\t" << calc_area()
            << "\nОбъём:\t\t" << calc_volume()
            << std::endl;
    }

private:
    IFigure* m_base;
    double* m_height;
}; // class Cylinder

#endif

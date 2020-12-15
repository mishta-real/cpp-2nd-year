#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "figure.hpp"

#include <iostream>

constexpr double PI = 3.141592;

class Circle : virtual public IFigure {
public:
    Circle()
    {
        m_radius = new double;
        *m_radius = 0;
    }

    explicit Circle( const double t_radius )
    {
        m_radius = new double;
        *m_radius = t_radius;
    }

    Circle operator=( const Circle& t_circle )
    {
        if ( this != &t_circle ) {
            m_radius = new double;
            *m_radius = *(t_circle.m_radius);
        }

        return *this;
    }

    Circle( const Circle& t_circle )
    {
        m_radius = new double;
        *m_radius = *(t_circle.m_radius);
    }

    virtual ~Circle() override
    {
        delete m_radius;
    }

    virtual Circle* copy() const override
    {
        return new Circle( *this );
    }

    virtual double calc_area() const override
    {
        return PI * (*m_radius) * (*m_radius);
    }

    virtual double calc_perimeter() const override
    {
        return 2 * PI * (*m_radius);
    }

    virtual void show() const override
    {
        std::cout
            << "КРУГ"
            << "\nРадиус:\t\t" << (*m_radius)
            << "\nДиаметр:\t" << (*m_radius) * 2
            << "\nДлина:\t\t" << calc_perimeter()
            << "\nПлощадь:\t" << calc_area()
            << std::endl;
    }

private:
    double* m_radius;
}; // class Circle : virtual class IFigure

#endif

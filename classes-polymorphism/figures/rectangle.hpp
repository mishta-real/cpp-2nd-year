#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "figure.hpp"

#include <iostream>

class Rectangle : virtual public IFigure {
public:
    Rectangle()
    {
        m_length = new double;
        *m_length = 0;

        m_width = new double;
        *m_width = 0;
    }

    explicit Rectangle( const double t_side )
    {
        m_length = new double;
        *m_length = t_side;

        m_width = new double;
        *m_width = t_side;
    }

    explicit Rectangle( const double t_side1, const double t_side2 )
    {
        m_length = new double;
        m_width = new double;

        if ( t_side1 > t_side2 ) {
            *m_length = t_side1;
            *m_width = t_side2;
        }
        else {
            *m_length = t_side2;
            *m_width = t_side1;
        }
    }

    Rectangle operator=( const Rectangle& t_rectangle )
    {
        if ( this != &t_rectangle ) {
            m_length = new double;
            *m_length = *(t_rectangle.m_length);

            m_width = new double;
            *m_width = *(t_rectangle.m_width);
        }

        return *this;
    }

    Rectangle( const Rectangle& t_rectangle )
    {
        m_length = new double;
        *m_length = *(t_rectangle.m_length);

        m_width = new double;
        *m_width = *(t_rectangle.m_width);
    }

    virtual ~Rectangle() override
    {
        delete m_length;
        delete m_width;
    }

    virtual Rectangle* copy() const override
    {
        return new Rectangle( *this );
    }

    virtual double calc_area() const override
    {
        return (*m_length) * (*m_width);
    }

    virtual double calc_perimeter() const override
    {
        return 2 * ((*m_length) + (*m_width));
    }

    virtual void show() const override
    {
        std::cout
            << "ПРЯМОУГОЛЬНИК"
            << "\nДлина:\t\t" << (*m_length)
            << "\nШирина:\t\t" << (*m_width)
            << "\nПериметр:\t" << calc_perimeter()
            << "\nПлощадь:\t" << calc_area()
            << std::endl;
    }

private:
    double* m_length;
    double* m_width;
}; // class Rectangle : virtual public IFigure

#endif

#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "figure.hpp"

#include <iostream>

class Parallelogram : virtual public IFigure {
public:
    Parallelogram()
    {
        m_base_length = new double;
        *m_base_length = 0;

        m_side_length = new double;
        *m_side_length = 0;

        m_height = new double;
        *m_height = 0;
    }

    explicit Parallelogram( const double t_side )
    {
        m_base_length = new double;
        *m_base_length = t_side;

        m_side_length = new double;
        *m_side_length = t_side;

        m_height = new double;
        *m_height = t_side;
    }

    explicit Parallelogram(
            const double t_base_length,
            const double t_side_length,
            const double t_height
    ) {
        m_base_length = new double;
        *m_base_length = t_base_length;

        m_side_length = new double;
        *m_side_length = t_side_length;

        m_height = new double;
        *m_height = t_height;
    }

    Parallelogram operator=( const Parallelogram& t_parallelogram )
    {
        if ( this != &t_parallelogram ) {
            m_base_length = new double;
            *m_base_length = *(t_parallelogram.m_base_length);

            m_side_length = new double;
            *m_side_length = *(t_parallelogram.m_side_length);

            m_height = new double;
            *m_height = *(t_parallelogram.m_height);
        }

        return *this;
    }

    Parallelogram( const Parallelogram& t_parallelogram )
    {
        m_base_length = new double;
        *m_base_length = *(t_parallelogram.m_base_length);

        m_side_length = new double;
        *m_side_length = *(t_parallelogram.m_side_length);

        m_height = new double;
        *m_height = *(t_parallelogram.m_height);
    }

    virtual ~Parallelogram() override
    {
        delete m_base_length;
        delete m_side_length;
        delete m_height;
    }

    virtual Parallelogram* copy() const override
    {
        return new Parallelogram( *this );
    }

    virtual double calc_area() const override
    {
        return (*m_base_length) * (*m_height);
    }

    virtual double calc_perimeter() const override
    {
        return 2 * ((*m_base_length) + (*m_side_length));
    }

    virtual void show() const override
    {
        std::cout
            << "ПАРАЛЛЕЛОГРАММ"
            << "\nДлина основания:\t" << (*m_base_length)
            << "\nВысота:\t\t\t" << (*m_height)
            << "\nПериметр:\t\t" << calc_perimeter()
            << "\nПлощадь:\t\t" << calc_area()
            << std::endl;
    }

private:
    double* m_base_length;
    double* m_side_length;
    double* m_height;
}; // class Parallelogram : virtual public IFigure

#endif

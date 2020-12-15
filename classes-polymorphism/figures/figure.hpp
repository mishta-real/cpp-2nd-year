#ifndef FIGURE_HPP
#define FIGURE_HPP

class IFigure {
public:
    virtual ~IFigure() {};

    virtual IFigure* copy() const = 0;

    virtual double calc_area() const = 0;
    virtual double calc_perimeter() const = 0;

    virtual void show() const = 0;
}; // class IFigure

#endif

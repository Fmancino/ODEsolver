/**
 * SinCos.hpp
 *
 * Created on: Dic, 2015
 *
 *     Author: Francesco Mancino
 *
 *Description: Derived class from Righthandside. Contructs a function of the type: f(y, t) = a*sin(c*y)+b*cos(d*y)
 */

/// \brief Class that allows the user to specify a function of the type f(y, t) = a*sin(c*y)+b*cos(d*y) for the right hand side of the ODE.

#ifndef SINCOSHEADERDEF
#define SINCOSHEADERDEF

#include <cmath>
#include "Righthandside.hpp"


template <class T> class SinCos: public Righthandside
{
    private:
    T a, b, c, d;
    public:
    SinCos() // Default constructor
        {
            SetGradientInfo(true);
            a = 0;
            b = 0;
            c = 1;
            d = 1;
        }

    ~SinCos() // Destructor
    {}

    /// Constructor for a sine function : a*sin(y) (for constructing a pure cosine function  it is possible to call SinCos(0, 1))
    SinCos(T a1)
    {
        SetGradientInfo(true);
        a = a1;
        b = 0;
        c = 1;
        d = 1;
    }

    /// Constructor for a function  of the type: a*sin(y)+b*cos(y)
    SinCos(T a1, T b1)
    {
        SetGradientInfo(true);
        a = a1;
        b = b1;
        c = 1;
        d = 1;
    }

    /// Constructor for a function  of the type: f(y, t) = a*sin(c*y)+b*cos(d*y)
    SinCos(T a1, T b1, T c1, T d1)
    {
        SetGradientInfo(true);
        a = a1;
        b = b1;
        c = c1;
        d = d1;
    }

    virtual double value(double y, double t) const // Returns the value of the function
    {
        return a*sin(c*y)+b*cos(d*y);
    }

    virtual double gradient(double y, double t) const // Returns derivative of the function
    {
        return a*c*cos(c*y)-b*d*sin(d*y);
    }
};

#endif

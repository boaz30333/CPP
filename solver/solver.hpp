#pragma once
#include <iostream>
#include <complex>

namespace solver
{
using namespace std;

class RealVariable
{
private:
    double _a, _b, _c;

public:

    const double a() const{
        return _a;
    }
     const    double b() const{
        return _b;
    }
      const   double c() const{
        return _c;
    }
    RealVariable()
    {
        _a=0;
        _b=1;
        _c = 0;
    }
        RealVariable(double a, double b, double c)
    {
        _a = a;
        _b = b;
        _c = c;
    }
        RealVariable(double c)
    {
        _a=0;
        _b=0;
        _c = c;
    }
        RealVariable(const RealVariable & other)
    {
        _a=other._a;
        _b=other._b;
        _c =other._c;
    }
const RealVariable& operator= (const RealVariable &other)
{
    // self-assignment guard
    if (this == &other)
        return *this;
 
    // do the copy
    _a = other._a; 
    _b = other._b; 
    _c=other._c;
    return *this;
}
    friend const RealVariable operator*(const RealVariable &x, const RealVariable &y);
    friend const RealVariable operator/(const RealVariable &x, double n);
    friend const RealVariable operator-(const RealVariable &x, const RealVariable &y);
    friend const RealVariable operator^(const RealVariable &n, int pow);
    friend const RealVariable operator==(const RealVariable &n, const RealVariable &m);
    friend const RealVariable operator+(const RealVariable &n, const RealVariable &m);
};

class ComplexVariable
{
private:
    std::complex<double> _a;
    std::complex<double> _b;
    std::complex<double> _c;


public:
  const  std::complex<double> a() const{
        return _a;
    }
     const   std::complex<double> b() const{
        return _b;
    }
      const  std::complex<double> c() const{
        return _c;
    }
    ComplexVariable()
    {
        _a=0;
        _b=1;
        _c=0;
    }
        ComplexVariable(const ComplexVariable & other)
    {
        _a=other._a;
        _b=other._b;
        _c =other._c;
    }
        ComplexVariable(const std::complex<double> a, const std::complex<double> b, const std::complex<double> c)
    {
        _a = a;
        _b = b;
        _c = c;
    }
    ComplexVariable(const std::complex<double> c )
    {
        _a=0;
        _b=0;
        _c=c;
    }
    ComplexVariable(double c)
    {
        _a=0;
        _b=0;
        _c=c;
    }
 ComplexVariable& operator= (const ComplexVariable &other)
{
    // self-assignment guard
    if (this == &other)
        return *this;
 
    // do the copy
    _a = other._a; 
    _b = other._b; 
    _c=other._c;
    return *this;
}

    friend const ComplexVariable operator*(const ComplexVariable &x, const ComplexVariable &y);
    friend const ComplexVariable operator^(const ComplexVariable &n, int pow);
    friend const ComplexVariable operator/(const ComplexVariable &x, double n);

    friend const ComplexVariable operator-(const ComplexVariable &x, const ComplexVariable &y);
    
    friend const ComplexVariable operator==(const ComplexVariable &n, const ComplexVariable &m);

    friend const ComplexVariable operator+(const ComplexVariable &n, const ComplexVariable &m);
};

double solve(const RealVariable &x);
std::complex<double> solve(const ComplexVariable &y);
} // namespace solver
#include <iostream>
#include <complex>
#include <string>
#include <stdexcept>
#include<math.h>
#include "solver.hpp"

// #define NULL __null

namespace solver

{
using namespace std;
const RealVariable operator*(const RealVariable &x, const RealVariable &y)
{
    return RealVariable(x._a*y._c+y._a*x._c+x._b*y._b,x._b*y._c+x._c*y._b,x._c*y._c);

}
const RealVariable operator-(const RealVariable &x, const RealVariable &y)
{
    return RealVariable(x._a-y._a,x._b-y._b,x._c-y._c);
}

const RealVariable operator/(const RealVariable &x, double n)
{
    if(n==0)        throw std::out_of_range{"empty word cant be find"};
    return RealVariable(x._a/n, x._b/n,x._c/n);

}

const RealVariable operator^(const RealVariable &x, int pow)
{

      if(pow==1) return x;
    if(pow==0) return 1;
    pow--;
    return x*(x^pow);
}

const RealVariable operator==(const RealVariable &x, const RealVariable &y)
{
    return RealVariable(x-y);
}

const RealVariable operator+(const RealVariable &x, const RealVariable &y)
{
    return RealVariable(x._a+y._a,x._b+y._b,x._c+y._c);
}

double solve(const RealVariable &y)
{

    double a= y.a();
    double b= y.b();
    double c= y.c();
      if (a==0){
          if(b==0)    throw std::out_of_range{"empty word cant be find"};
        return double(-c/b);
    }
    else{
        if(double(std::pow(b,2)-double(double(4*a)*c))<0) throw std::out_of_range{"empty word cant be find"};
        return double((-b +sqrt(double(std::pow(b,2)-double(double(4*a)*c))))) /double(2*a);
    }
}

const ComplexVariable operator*(const ComplexVariable &x, const ComplexVariable &y)
{
    return ComplexVariable(x._a*y._c+y._a*x._c+x._b*y._b,x._b*y._c+x._c*y._b,x._c*y._c);
}

const ComplexVariable operator/(const ComplexVariable &x, double n)
{
    if(n==0)         throw std::out_of_range{"mmm"};
    return ComplexVariable(x._a/n, x._b/n,x._c/n);
}

const ComplexVariable operator-(const ComplexVariable &x, const ComplexVariable &y)
{
    return ComplexVariable(x._a-y._a,x._b-y._b,x._c-y._c);
}

const ComplexVariable operator^(const ComplexVariable &x, int pow)
{
      if(pow==1) return x;
    if(pow==0) return 1;
    pow--;
    return x*(x^pow);
}
const ComplexVariable operator+(const ComplexVariable &x, const ComplexVariable &y)
{
    return ComplexVariable(x._a+y._a,x._b+y._b,x._c+y._c);
}

const ComplexVariable operator==(const ComplexVariable &x, const ComplexVariable &y)
{
    return ComplexVariable(x-y);
}

// const ComplexVariable operator-(const ComplexVariable &n)
// {
//     return ComplexVariable(0);
// }

std::complex<double> solve(const ComplexVariable &y)
{

    std::complex<double> a= y.a();
    std::complex<double> b= y.b();
    std::complex<double> c= y.c();
      if (a.imag()==0&&a.real()==0){
             if(b.imag()==0&&b.real()==0)         throw std::out_of_range{"empty word cant be find"};
        return (-c/b);
      }
    else{
        return complex<double>(-b +sqrt(complex<double>(std::pow(b,2)-complex<double>((complex<double>(a))*4.0*c)))) /complex<double>(2.0*a);
    }
}

} // namespace solver
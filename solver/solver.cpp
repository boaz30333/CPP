#include <iostream>
#include <complex>
#include <string>
#include "solver.hpp"

// #define NULL __null

namespace solver
{
using namespace std;

const RealVariable operator*(const RealVariable &x, const RealVariable &y)
{
    return RealVariable(x._a*y._c+y._a*x._c+x._b*y._b,x._b*y._c+x._c*y._b,x._c*y._c);
}
     const RealVariable operator*(double x, const RealVariable &y){
 return RealVariable(y._a*x,y._b*x,y._c*x);
     }
 const RealVariable operator*(const RealVariable &y ,double x){
 return RealVariable(y._a*x,y._b*x,y._c*x);
    }
const RealVariable operator-(const RealVariable &x, const RealVariable &y)
{
    return RealVariable(x._a-y._a,x._b-y._b,x._c-y._c);
}
 const RealVariable operator-(const RealVariable &y ,double x){
 return RealVariable(y._a,y._b,y._c-x);
    }
const RealVariable operator-(double x, const RealVariable &y){
 return RealVariable(y._a,y._b,y._c-x);
    }
const RealVariable operator/(const RealVariable &x, double n)
{
    return RealVariable(x._a/n, x._b/n,x._c/n);
}

const RealVariable operator^(const RealVariable &x, int pow)
{
      if(pow==1) return x;
    if(pow==0) return RealVariable(1);
    pow--;
    return x*(x^pow);
}

const RealVariable operator==(const RealVariable &x, double y)
{
    return RealVariable(x-y);
}
const RealVariable operator==(double x, const RealVariable &y)
{
    return RealVariable(y-x);
}
const RealVariable operator==(const RealVariable &x, const RealVariable &y)
{
    return RealVariable(y-x);
}
const RealVariable operator+(const RealVariable &x, const RealVariable &y)
{
    return RealVariable(x._a+y._a,x._b+y._b,x._c+y._c);
}
 const RealVariable operator+(const RealVariable &y ,double x){
 return RealVariable(y._a,y._b,y._c+x);
    }
const RealVariable operator+(double x, const RealVariable &y){
 return RealVariable(y._a,y._b,y._c+x);
    }

double solve(const RealVariable &y)
{

    double a= y.a();
    double b= y.b();
    double c= y.c();
      if (a==0){
        return -c / b;    
    }
    else{
        return (-b +sqrt(b*b-4*a*c))/(2*a);
    }
}

const ComplexVariable operator*(const ComplexVariable &x, const ComplexVariable &y)
{
    return ComplexVariable(x._a*y._c+y._a*x._c+x._b*y._b,x._b*y._c+x._c*y._b,x._c*y._c);
}
     const ComplexVariable operator*(double x, const ComplexVariable &y){
 return ComplexVariable(y._a*x,y._b*x,y._c*x);
     }
 const ComplexVariable operator*(const ComplexVariable &y ,double x){
 return ComplexVariable(y._a*x,y._b*x,y._c*x);
    }
const ComplexVariable operator/(const ComplexVariable &x, double n)
{
    return ComplexVariable(x._a/n, x._b/n,x._c/n);
}

const ComplexVariable operator-(const ComplexVariable &x, const ComplexVariable &y)
{
    return ComplexVariable(x._a-y._a,x._b-y._b,x._c-y._c);
}
 const ComplexVariable operator-(const ComplexVariable &y ,double x){
 return ComplexVariable(y._a,y._b,y._c-x);
    }
const ComplexVariable operator-(double x, const ComplexVariable &y){
 return ComplexVariable(y._a,y._b,y._c-x);
    }
const ComplexVariable operator^(const ComplexVariable &x, int pow)
{
      if(pow==1) return x;
    if(pow==0) return ComplexVariable(1.+0i);
    pow--;
    return x*(x^pow);
}
const ComplexVariable operator+(const ComplexVariable &x, const ComplexVariable &y)
{
    return ComplexVariable(x._a+y._a,x._b+y._b,x._c+y._c);
}
 const ComplexVariable operator+(const ComplexVariable &y ,double x){
 return ComplexVariable(y._a,y._b,y._c+x);
    }
const ComplexVariable operator+(double x, const ComplexVariable &y){
 return ComplexVariable(y._a,y._b,y._c+x);
    }
const ComplexVariable operator==(const ComplexVariable &x, const ComplexVariable &y)
{
    return ComplexVariable(x-y);
}
 const ComplexVariable operator==(const ComplexVariable &y ,double x){
 return ComplexVariable(y-x);
    }
const ComplexVariable operator==(double x, const ComplexVariable &y){
 return ComplexVariable(y-x);
    }
std::complex<double> solve(const ComplexVariable &y)
{
    // std::complex<double> a= y.a();
    // std::complex<double> b= y.b();
    // std::complex<double> c= y.c();
    
    //   if (a==0.0+0i){
    //     return -c / b;
    // }
    // else{
    //     return (-b +sqrt(b*b-4*a*c))/(2*a);
    // }
    return 0;
}
} // namespace solver
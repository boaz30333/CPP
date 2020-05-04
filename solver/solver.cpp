#include <iostream>
#include <complex>
#include <string>
#include "solver.hpp"


<<<<<<< HEAD
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
=======
namespace solver{
    using namespace std;
    double operator*(double n, RealVariable x){
        return 0;
    }

    double operator*(RealVariable n, double m){
         return 0;
    }
        double operator*(RealVariable n,RealVariable s){
         return 0;
    }

    double operator/(double n, RealVariable x){
        return 0;
    }

    double operator/(RealVariable n, double m){
         return 0;
    }

    double operator-(RealVariable n){
         return 0;
    }

    double operator-(double n, RealVariable x){
        return 0;
    }

    double operator-(RealVariable n, double m){
         return 0;
    }

    double operator^(RealVariable n, double pow){
         return 0;
    }

    double operator==(RealVariable n, RealVariable m){
         return 0;
    }

    double operator==(double n, RealVariable x){
        return 0;
    }

    double operator==(RealVariable n, double m){
         return 0;
    }

    double RealVariable::operator()(){
        return 0;
    }

    double operator+(RealVariable n, RealVariable m){
         return 0;
    }

    double operator+(RealVariable n, double m){
         return 0;
    }

    double operator+(double n, RealVariable m){
         return 0;
    }



    ComplexVariable operator*(double n, ComplexVariable x){
        return x;
    }

    ComplexVariable operator*(ComplexVariable n, double x){
        return n;
    }
        ComplexVariable operator*(ComplexVariable n, ComplexVariable s){
        return n;
    }

    ComplexVariable operator/(double x, ComplexVariable n){
        return n;
    }

    ComplexVariable operator/(ComplexVariable x, double n){
        return x;
    }

    ComplexVariable operator-(ComplexVariable n){
        return n;
    }

    ComplexVariable operator-(ComplexVariable x, double n){
        return x;
    }

    ComplexVariable operator-(double x, ComplexVariable n){
        return n;
    }

      ComplexVariable operator-(ComplexVariable n, ComplexVariable m){
        return n;
    }

      ComplexVariable operator-(ComplexVariable n, std::complex<double> m){
        return n;
    }

      ComplexVariable operator-(std::complex<double> n, ComplexVariable m){
        return m;
    }

    ComplexVariable operator^(ComplexVariable n, double pow){
        return n;
    }

    ComplexVariable operator==(ComplexVariable n, ComplexVariable m){
        return n;
    }

    ComplexVariable operator==(ComplexVariable n, std::complex<double> m){
        return n;
    }

    ComplexVariable operator==(std::complex<double> n, ComplexVariable m){
        return m;
    }

    ComplexVariable operator==(ComplexVariable n, double m){
        return n;
    }

    ComplexVariable operator==(double x, ComplexVariable n){
        return n;
    }

    ComplexVariable operator==(std::complex<double> n, double m){
        ComplexVariable x;
        return x;
    }

    ComplexVariable operator+(ComplexVariable n, ComplexVariable m){
        return n;
    }

    ComplexVariable operator+(ComplexVariable n, double m){
        return n;
    }

    ComplexVariable operator+(double n, ComplexVariable x){
        return x;
    }

    ComplexVariable operator+(ComplexVariable n, std::complex<double> m){
        return n;
    }

    ComplexVariable operator+(std::complex<double> n, ComplexVariable m){
        return m;
    }

    ComplexVariable ComplexVariable::operator()(ComplexVariable n){
        return n;
    }

    double solve(double x){
        return 0;
    }

    std::complex<double> solve(ComplexVariable y){
        return 0;
    }
}
>>>>>>> f866822b4f369fc5b18f17586f151adcf534e6dc

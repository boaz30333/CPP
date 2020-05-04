#pragma once
#include <iostream>
#include <complex>
#include <math.h>

namespace solver
{
using namespace std;

class RealVariable
{
private:
    double _a, _b, _c;

<<<<<<< HEAD
public:
=======
    class RealVariable{
        private:
            double _x;
            double _y;
            double _z;
        public:
            // RealVariable(double x):
            //     _val(x){}
        	double x() const {
		        return _x;
	        }
                    	double y() const {
		        return _y;
	        }
                    	double z() const {
		        return _z;
	        }
>>>>>>> f866822b4f369fc5b18f17586f151adcf534e6dc

    double a() const{
        return _a;
    }
       double b() const{
        return _b;
    }
      const   double c() const{
        return _c;
    }
        RealVariable(double c)
    {
        _a=0;
        _b=0;
        _c=c;
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

<<<<<<< HEAD
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
    friend const RealVariable operator*(double x, const RealVariable &y);
    friend const RealVariable operator*(const RealVariable &y, double x);

    friend const RealVariable operator/(const RealVariable &x, double n);

   friend const RealVariable operator-(const RealVariable &x, const RealVariable &y);
        friend const RealVariable operator-(double x, const RealVariable &y);
    friend const RealVariable operator-(const RealVariable &y, double x);
    friend const RealVariable operator^(const RealVariable &n, int pow);
    friend const RealVariable operator==(const RealVariable &n, const RealVariable &m);
    friend const RealVariable operator==(double x, const RealVariable &y);
    friend const RealVariable operator==(const RealVariable &y, double x);
    friend const RealVariable operator+(const RealVariable &n, const RealVariable &m);
        friend const RealVariable operator+(double x, const RealVariable &y);
    friend const RealVariable operator+(const RealVariable &y, double x);
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
    // ComplexVariable(double c)
    // {
    //     _a=0;
    //     _b=0;
    //     _c=c;
    // }
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
    friend const ComplexVariable operator*(double x, const ComplexVariable &y);
    friend const ComplexVariable operator*(const ComplexVariable &y ,double x);

    friend const ComplexVariable operator^(const ComplexVariable &n, int pow);
    friend const ComplexVariable operator/(const ComplexVariable &x, double n);
=======
            friend double operator*(double n, RealVariable x);
            friend double operator*(RealVariable n, double m);
            friend double operator*(RealVariable n, RealVariable s);
            friend double operator/(double n, RealVariable x);
            friend double operator/(RealVariable n, double m);
            friend double operator-(RealVariable n);
            friend double operator-(double n, RealVariable x);
            friend double operator-(RealVariable n, double m);
            friend double operator^(RealVariable n, double pow);
            friend double operator==(RealVariable n, RealVariable m);
            friend double operator==(double n, RealVariable x);
            friend double operator==(RealVariable n, double m);
            double operator()();
            friend double operator+(RealVariable n, RealVariable m);
            friend double operator+(RealVariable n, double m);
            friend double operator+(double n, RealVariable m);
        
    };

    class ComplexVariable{
      private:
            double _x;
            double _y;
            double _z;
        public:
            // RealVariable(double x):
            //     _val(x){}
        	double x() const {
		        return _x;
	        }
                    	double y() const {
		        return _y;
	        }
                    	double z() const {
		        return _z;
	        }
           friend ComplexVariable operator*(double n, ComplexVariable x);
           friend ComplexVariable operator*(ComplexVariable x, double n);
           friend ComplexVariable operator*(ComplexVariable x, ComplexVariable y);
           friend ComplexVariable operator/(ComplexVariable x, double n);
           friend ComplexVariable operator/(double n, ComplexVariable x);
            friend ComplexVariable operator-(ComplexVariable n);
            friend ComplexVariable operator-(ComplexVariable n, ComplexVariable m);
            friend ComplexVariable operator-(ComplexVariable x, double n);
            friend ComplexVariable operator-(double n, ComplexVariable m);
            friend ComplexVariable operator-(ComplexVariable n, std::complex<double> m);
            friend ComplexVariable operator-(std::complex<double> n, ComplexVariable m);
            friend ComplexVariable operator^(ComplexVariable n, double pow);
            friend ComplexVariable operator==(ComplexVariable n, ComplexVariable m);
            friend ComplexVariable operator==(ComplexVariable n, std::complex<double> m);
            friend ComplexVariable operator==(std::complex<double> n, ComplexVariable m);
            friend ComplexVariable operator==(ComplexVariable n, double m);
            friend ComplexVariable operator==(double n, ComplexVariable x);
            friend ComplexVariable operator==(std::complex<double> n, double m);
            friend ComplexVariable operator+(double n, std::complex<double> x);
            ComplexVariable operator()(ComplexVariable n);
            friend ComplexVariable operator+(ComplexVariable n, ComplexVariable m);
            friend ComplexVariable operator+(ComplexVariable n, double m);
            friend ComplexVariable operator+(double n, ComplexVariable x);
            friend ComplexVariable operator+(ComplexVariable n, std::complex<double>);
            friend ComplexVariable operator+(std::complex<double> n, ComplexVariable m);
    };

    // double operator*(double n, RealVariable x);
    // double operator-(RealVariable n);
    // double operator-(double n, RealVariable x);
    // double operator^(RealVariable n, double pow);
    // double operator==(RealVariable n, RealVariable m);
    // double operator+(RealVariable n, RealVariable m);
    // double operator+(RealVariable n, double m);
    // double operator+(double n, RealVariable m);
  

    // ComplexVariable operator*(double n, ComplexVariable x);
    // ComplexVariable operator/(ComplexVariable x, double n);
    // ComplexVariable operator-(ComplexVariable n);
    // ComplexVariable operator-(ComplexVariable x, double n);
    // ComplexVariable operator-(ComplexVariable n, ComplexVariable m);
    // ComplexVariable operator-(ComplexVariable n, std::complex<double> m);
    // ComplexVariable operator^(ComplexVariable n, double pow);
    // ComplexVariable operator==(ComplexVariable n, ComplexVariable m);
    // ComplexVariable operator==(ComplexVariable n, std::complex<double> m);
    // ComplexVariable operator==(ComplexVariable n, double m);
    // ComplexVariable operator==(std::complex<double> n, double m);
    // ComplexVariable operator+(ComplexVariable n, ComplexVariable m);
    // ComplexVariable operator+(ComplexVariable n, double m);
    // ComplexVariable operator+(double n, ComplexVariable x);
    // ComplexVariable operator+(ComplexVariable n, std::complex<double>);
>>>>>>> f866822b4f369fc5b18f17586f151adcf534e6dc

    friend const ComplexVariable operator-(const ComplexVariable &x, const ComplexVariable &y);
    friend const ComplexVariable operator-(double x, const ComplexVariable &y);
    friend const ComplexVariable operator-(const ComplexVariable &y ,double x);
    friend const ComplexVariable operator==(const ComplexVariable &n, const ComplexVariable &m);
    friend const ComplexVariable operator==(double x, const ComplexVariable &y);
    friend const ComplexVariable operator==(const ComplexVariable &y ,double x);
    friend const ComplexVariable operator+(const ComplexVariable &n, const ComplexVariable &m);
        friend const ComplexVariable operator+(double x, const ComplexVariable &y);
    friend const ComplexVariable operator+(const ComplexVariable &y ,double x);
};

double solve(const RealVariable &x);
std::complex<double> solve(const ComplexVariable &y);
} // namespace solver
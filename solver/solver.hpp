#pragma once
#include <iostream>
#include <complex>


namespace solver{
    using namespace std;

    class RealVariable{
        private:
            double x;
        public:
            friend double operator*(double n, RealVariable x);
            friend double operator/(double n, RealVariable x);
            friend double operator-(RealVariable n);
            friend double operator-(double n, RealVariable x);
            friend double operator^(RealVariable n, int pow);
            friend double operator==(RealVariable n, RealVariable m);
            double operator()();
            friend double operator+(RealVariable n, RealVariable m);

    };

    class ComplexVariable{
        private:
            double re;
            double im;
        public: 
           friend ComplexVariable operator*(int n, ComplexVariable x);
           friend ComplexVariable operator/(ComplexVariable x, int n);
            friend ComplexVariable operator-(ComplexVariable n);
            friend ComplexVariable operator-(ComplexVariable x, int n);
            friend ComplexVariable operator-(ComplexVariable n, ComplexVariable m);
            friend ComplexVariable operator^(ComplexVariable n, int pow);
            friend ComplexVariable operator==(ComplexVariable n, ComplexVariable m);
            friend ComplexVariable operator==(ComplexVariable n, int m);
            ComplexVariable operator()(ComplexVariable n);
            friend ComplexVariable operator+(ComplexVariable n, ComplexVariable m);
            friend ComplexVariable operator+(ComplexVariable n, int m);
            friend ComplexVariable operator+(int n, ComplexVariable x);
            friend ComplexVariable operator+(ComplexVariable n, std::complex<double>);
    };

    double operator*(double n, RealVariable x);
    double operator-(RealVariable n);
    double operator-(double n, RealVariable x);
    double operator^(RealVariable n, int pow);
    double operator==(RealVariable n, RealVariable m);
    double operator+(RealVariable n, RealVariable m);


    ComplexVariable operator*(int n, ComplexVariable x);
    ComplexVariable operator/(ComplexVariable x, int n);
    ComplexVariable operator-(ComplexVariable n);
    ComplexVariable operator-(ComplexVariable x, int n);
    ComplexVariable operator-(ComplexVariable n, ComplexVariable m);
    ComplexVariable operator^(ComplexVariable n, int pow);
    ComplexVariable operator==(ComplexVariable n, ComplexVariable m);
    ComplexVariable operator==(ComplexVariable n, int m);
    ComplexVariable operator+(ComplexVariable n, ComplexVariable m);
    ComplexVariable operator+(ComplexVariable n, int m);
    ComplexVariable operator+(int n, ComplexVariable x);
    ComplexVariable operator+(ComplexVariable n, std::complex<double>);

    double solve(double x);
    std::complex<double> solve(ComplexVariable y);
}
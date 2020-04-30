#include <iostream>
#include <complex>
#include <string>
#include "solver.hpp"


namespace solver{
    using namespace std;
    double operator*(double n, RealVariable x){
        return 0;
    }

    double operator*(RealVariable n, double m){
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
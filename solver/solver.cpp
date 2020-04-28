#include <iostream>
#include <complex>
#include <string>
#include "solver.hpp"

// #define NULL __null

namespace solver{
    using namespace std;
    double operator*(double n, RealVariable x){
        return 0;
    }

    double operator/(double n, RealVariable x){
        return 0;
    }

    double operator-(RealVariable n){
         return 0;
    }

    double operator-(double n, RealVariable x){
        return 0;
    }

    double operator^(RealVariable n, int pow){
         return 0;
    }

    double operator==(RealVariable n, RealVariable m){
         return 0;
    }

    double RealVariable::operator()(){
        return 0;
    }

    double operator+(RealVariable n, RealVariable m){
         return 0;
    }

    double operator+(RealVariable n, int m){
         return 0;
    }

    double operator+(int n, RealVariable m){
         return 0;
    }

    double operator+(RealVariable n, double m){
         return 0;
    }

    double operator+(double n, RealVariable m){
         return 0;
    }



    ComplexVariable operator*(int n, ComplexVariable x){
        return x;
    }

    ComplexVariable operator/(ComplexVariable x, int n){
        return x;
    }

    ComplexVariable operator-(ComplexVariable n){
        return n;
    }

    ComplexVariable operator-(ComplexVariable x, int n){
        return x;
    }

      ComplexVariable operator-(ComplexVariable n, ComplexVariable m){
        return n;
    }

    ComplexVariable operator^(ComplexVariable n, int pow){
        return n;
    }

    ComplexVariable operator==(ComplexVariable n, ComplexVariable m){
        return n;
    }

    ComplexVariable operator==(ComplexVariable n, int m){
        return n;
    }

    ComplexVariable operator+(ComplexVariable n, ComplexVariable m){
        return n;
    }

    ComplexVariable operator+(ComplexVariable n, int m){
        return n;
    }

    ComplexVariable operator+(int n, ComplexVariable x){
        return x;
    }

    ComplexVariable operator+(ComplexVariable n, std::complex<double> m){
        return n;
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
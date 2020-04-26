#include <iostream>
#include <complex>
#include <string>
#include "solver.hpp"

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



    ComplexVariable operator*(int n, ComplexVariable x){
        return;
    }

    ComplexVariable operator-(ComplexVariable n){
        return;
    }

    ComplexVariable operator-(int n, ComplexVariable x){
        return;
    }

    ComplexVariable operator^(ComplexVariable n, int pow){
        return;
    }

    ComplexVariable operator==(ComplexVariable n, ComplexVariable m){
        return;
    }

    ComplexVariable operator+(ComplexVariable n, ComplexVariable m){
        return;
    }

    ComplexVariable ComplexVariable::operator()(ComplexVariable n){
        return;
    }

    double solve(double x){
        return 0;
    }

    std::complex<double> solve(ComplexVariable y){
        return 0;
    }
}
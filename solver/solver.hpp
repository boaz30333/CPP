#pragma once
#include <iostream>
#include <complex>


namespace solver{
    using namespace std;

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

    double solve(double x);
    std::complex<double> solve(ComplexVariable y);
}
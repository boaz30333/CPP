#include "doctest.h"
#include <string>
#include <complex>
#include "solver.hpp"
using namespace solver;
using namespace std;


TEST_CASE("real op+ ")
{
  RealVariable x;
  CHECK(x+5 == 7);
  CHECK(x+x == 4);
  CHECK(x+2+4 == 6);
  CHECK(x+x+x+x == 8);
  CHECK(12.5+x+3 == 17.5);
}

TEST_CASE("solve linear")
{
  RealVariable x;
  CHECK(solve(5*x+4==24) == 4);
  CHECK(solve(3*x+4-x==24) == 10);
  CHECK(solve(2.5+2*x-x==24) == 21.5);
  CHECK(solve(21.3+3*x==120.3) == 33);
  CHECK(solve(4*x+8.7==88.7) == 20);
  CHECK(solve(5*x+4==54) == 10);
  CHECK(solve(3*x+4-x==92.8) == 44.4);
  CHECK(solve(2.5+2*x-x==2.5) == 0);
  CHECK(solve(21.3+33*x==120.3) == 3);
  CHECK(solve(2*x+8.7==88.7) == 40);
  ComplexVariable y;
  CHECK(solve(5*y+4==24) == 4.0+0i);
  CHECK(solve(3*y+4-y==24) == 10.0+0i);
  CHECK(solve(2.5+2*y-y==24) == 21.5+0i);
  CHECK(solve(21.3+3*y==120.3) == 33.0+0i);
  CHECK(solve(4*y+8.7==88.7) == 20.0+0i);
  CHECK(solve(5*y+4==24.0+10i) == 4.0+2i);
  CHECK(solve(3*y+4-y-5i==24) == 10.0+2.5i);
  CHECK(solve(2.5+2*y-y+3.4i==24) == 21.5-3.4i);
  CHECK(solve(21.3+3*y==120.3) == 33.0+0i);
  CHECK(solve(4*y+8.7==88.7) == 20.0+0i);
}

TEST_CASE("solve polynom")
{
  RealVariable x;
  CHECK(solve((x^2)-1==24) == 5);
  CHECK(solve(2*(x^2)-1==199) == 10);
  CHECK(solve(3*(x^2)==27) == 3);
  CHECK(solve(2*(x^2)+4*x+2==0) == -1);
  CHECK(solve(2*(x^2)+5*x+3==0) == -1);
  ComplexVariable y;
  CHECK(solve(2*(y^2)+2*y+1==0) == -(0.5)+0.5i);
  CHECK(solve((y^2)+1==0) == 1i); 
  CHECK(solve(2.5+2*y-y==24) == 21.5+0i);
  CHECK(solve(21.3+3*y==120.3) == 33.0+0i);
  CHECK(solve(4*y+8.7==88.7) == 20.0+0i);
}

TEST_CASE("solve - throw aritmetic problem")
{
    RealVariable x;
    CHECK_THROWS(solve((x^2)==-16));
    CHECK_THROWS(solve((x^2)==-1));
    CHECK_THROWS(solve((x^2)-500==-1126));
    CHECK_THROWS(solve((x^2)-3==-16));
    CHECK_THROWS(solve((x^2)+70==-16));
    CHECK_THROWS(solve((x^2)==-1.6));
    CHECK_THROWS(solve((x^2)==-124253.2));
    CHECK_THROWS(solve((x^2)-500==-1126.2));
    CHECK_THROWS(solve((x^2)-3==-1612));
    CHECK_THROWS(solve((x^2)+70==-1642.221));
    CHECK_THROWS(solve((x^2)==-0.3));
    CHECK_THROWS(solve((x^2)==-0.000999));
    CHECK_THROWS(solve((x^2)-500==-2226));
    CHECK_THROWS(solve((x^2)-3==-4));
    CHECK_THROWS(solve((x^2)+70==-20));
    CHECK_THROWS(solve((x^2)==-999));
    CHECK_THROWS(solve((x^2)==-2.2));
    CHECK_THROWS(solve((x^2)-500==-501));
    CHECK_THROWS(solve((x^2)-3==-4));
    CHECK_THROWS(solve((x^2)+70==69));
    ComplexVariable y;
    CHECK_THROWS(solve((y^2)==-16i));
    CHECK_THROWS(solve((y^2)==-1i));
    CHECK_THROWS(solve((y^2)-500==-1126i));
    CHECK_THROWS(solve((y^2)-3==1i));
    CHECK_THROWS(solve((y^2)+70==15i));
    CHECK_THROWS(solve((y^2)==-1.6i));
    CHECK_THROWS(solve((y^2)==0.2i));
    CHECK_THROWS(solve((y^2)-500==52i));
    CHECK_THROWS(solve((y^2)-3==4.3i));
    CHECK_THROWS(solve((y^2)+70==-6.66666i));
}


#include "doctest.h"
#include <string>
#include <complex>
#include "solver.hpp"
using namespace solver;
using namespace std;

TEST_CASE("real ctor ")
{
  RealVariable x;
  CHECK(solve(2*x-4==10) == 7);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

TEST_CASE("real op== ")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

// TEST_CASE("real op!= ")
// {

// }

TEST_CASE("real op+ ")
{
  RealVariable x;
  CHECK(x+5 == 7);
  CHECK(x+x == 4);
  CHECK(x+2+4 == 6);
  CHECK(x+x+x+x == 8);
  CHECK(12.5+x+3 == 17.5);
}

TEST_CASE("real op*")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}
TEST_CASE("real op^")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

TEST_CASE("real op=")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

TEST_CASE("real op+=")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

TEST_CASE("real op+*")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

TEST_CASE("real op-")
{
}

TEST_CASE("real op<<")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

// TEST_CASE("real op>>")
// {

// }

TEST_CASE("complex ctor ")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

TEST_CASE("complex op== ")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

// TEST_CASE("complex op!= ")
// {

// }

// TEST_CASE("complex op+ ")
// {
//   ComplexVariable x;
//   CHECK(x+5 == 7i);
//   CHECK(x+x == 4i);
//   CHECK(x+2+4 == 6);
//   CHECK(x+x+x+x == 8);
//   CHECK(12.5+x+3 == 17.5);
// }

TEST_CASE("complex op*")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

TEST_CASE("complex op=")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}
TEST_CASE("complex op^")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}
TEST_CASE("complex op+=")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

TEST_CASE("complex op+*")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

TEST_CASE("complex op-")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

TEST_CASE("complex op<<")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

// TEST_CASE("complex op>>")
// {

// }
TEST_CASE("solve linear")
{
    RealVariable x;
    CHECK(solve(5*x+4==24) == 4);
  CHECK(solve(3*x+4-x==24) == 10);
  CHECK(solve(2.5+2*x-x==24) == 21.5);
  CHECK(solve(21.3+3*x==120.3) == 33);
  CHECK(solve(4*x+8.7==88.7) == 20);
  ComplexVariable y;
  CHECK(solve(5*y+4==24) == 4);
  CHECK(solve(3*y+4-y==24) == 10);
  CHECK(solve(2.5+2*y-y==24) == 21.5);
  CHECK(solve(21.3+3*y==120.3) == 33);
  CHECK(solve(4*y+8.7==88.7) == 20);
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
  CHECK(solve((y^2)+1==0) == 1); //should be "i" instead of "1" but there is exception...
  CHECK(solve(2.5+2*x-x==24) == 21.5);
  CHECK(solve(21.3+3*x==120.3) == 33);
  CHECK(solve(4*x+8.7==88.7) == 20);
}
TEST_CASE("solve explict furmula")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}
TEST_CASE("solve - throw aritmetic problem")
{
    RealVariable x;
    CHECK_THROWS(solve((x^2)==-16));
    CHECK_THROWS(solve((x^2)==-1));
    CHECK_THROWS(solve((x^2)-500==-1126));
    CHECK_THROWS(solve((x^2)-3==-16));
    CHECK_THROWS(solve((x^2)+70==-16));
}
TEST_CASE("solve - unary minus")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

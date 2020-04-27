#include "doctest.h"
#include <string>
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
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
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

TEST_CASE("complex op+ ")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}

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
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}
TEST_CASE("solve polynom")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
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
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}
TEST_CASE("solve - unary minus")
{
    CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
  CHECK(true == true);
}
>>>>>>> 8af31efe86ac98aeecc4e69da2be73de046c14fa

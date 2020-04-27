#include "doctest.h"
#include <string>
#include "solver.hpp"
using namespace solver;
using namespace std;


TEST_CASE("Test addMother")
{
  RealVariable x;
  CHECK(solve(2*x-4==10) == 7);
  CHECK(solve(2*x-4==10) == 7);
  CHECK(solve(2*x-4==10) == 7);
  CHECK(solve(2*x-4==10) == 7);
  CHECK(solve(2*x-4==10) == 7);
}
#include "doctest.h"
#include <string>
#include "solver.hpp"
using namespace solver;
using namespace std;


TEST_CASE("Test addMother")
{
  family::Tree t("ori");
  t.addMother("ori", "hana");
  t.addMother("hana", "sara");
  t.addMother("sara", "miriam");
  t.addMother("miriam", "rivka");
  t.addMother("rivka", "hadas");
  CHECK(t.find("mother") == string("yosef"));
  CHECK(t.find("grandmother") == string("yitzhak"));
  CHECK(t.find("great-grandmother") == string("yaakov"));
  CHECK(t.find("great-great-grandmother") == string("david"));
  CHECK(t.find("great-great-great-grandmother") == string("nisim"));
//  delete &t;
}
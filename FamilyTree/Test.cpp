
#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

TEST_CASE("Test find")
{
  family::Tree t("ori");
  t.addFather("ori", "yosef");
  t.addMother("ori", "hana");
  t.addFather("yosef", "yitzhak");
  t.addMother("yosef", "sara");
  t.addFather("yitzhak", "yaakov");
  t.addMother("yitzhak", "miriam");
  t.addFather("yaakov", "david");
  t.addMother("yaakov", "keren");
  t.addFather("david", "nisim");
  t.addMother("david", "rivka");
     CHECK_NOTHROW(t.find("father") );
   CHECK_NOTHROW(t.find("mother") );
   CHECK_NOTHROW(t.find("grandfather") );
   CHECK_NOTHROW(t.find("grandmother") );
   CHECK_NOTHROW(t.find("great-grandfather") );
   CHECK_NOTHROW(t.find("great-grandmother") );
   CHECK_NOTHROW(t.find("great-great-grandfather") );
   CHECK_NOTHROW(t.find("great-great-grandmother") );
   CHECK_NOTHROW(t.find("great-great-great-grandfather"));
   CHECK_NOTHROW(t.find("great-great-great-grandmother") );
  CHECK(t.find("father") == string("yosef"));
  CHECK(t.find("mother") == string("hana"));
  CHECK(t.find("grandfather") == string("yitzhak"));
  CHECK(t.find("grandmother") == string("sara"));
  CHECK(t.find("great-grandfather") == string("yaakov"));
  CHECK(t.find("great-grandmother") == string("miriam"));
  CHECK(t.find("great-great-grandfather") == string("david"));
  CHECK(t.find("great-great-grandmother") == string("keren"));
  CHECK(t.find("great-great-great-grandfather") == string("nisim"));
  CHECK(t.find("great-great-great-grandmother") == string("rivka"));
  CHECK_THROWS(t.find("uncle"));
  CHECK_THROWS(t.find("aunt"));
  CHECK_THROWS(t.find("son"));
  CHECK_THROWS(t.find("daughter"));
  CHECK_THROWS(t.find("brother"));
  CHECK_THROWS(t.find("sister"));
  CHECK_THROWS(t.find("nephew"));
  CHECK_THROWS(t.find("niece"));
}

TEST_CASE("Test addFather")
{
  family::Tree t("ori");
  t.addFather("ori", "yosef");
  t.addFather("yosef", "yitzhak");
  t.addFather("yitzhak", "yaakov");
  t.addFather("yaakov", "david");
  t.addFather("david", "nisim");

  CHECK(t.find("father") == string("yosef"));
  CHECK(t.find("grandfather") == string("yitzhak"));
  CHECK(t.find("great-grandfather") == string("yaakov"));
  CHECK(t.find("great-great-grandfather") == string("david"));
  CHECK(t.find("great-great-great-grandfather") == string("nisim"));
}

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
}

TEST_CASE("Test relation")
{
  family::Tree t("ori");
  t.addFather("ori", "yosef");
  t.addMother("ori", "hana");
  t.addFather("yosef", "yitzhak");
  t.addMother("yosef", "sara");
  t.addFather("yitzhak", "yaakov");
  t.addMother("yitzhak", "miriam");
  t.addFather("yaakov", "david");
  t.addMother("yaakov", "keren");
  t.addFather("david", "nisim");
  t.addMother("david", "rivka");
    CHECK_NOTHROW(t.relation("ori"));
  CHECK_NOTHROW(t.relation("yosef"));
  CHECK_NOTHROW(t.relation("hana"));
  CHECK_NOTHROW(t.relation("yitzhak"));
  CHECK_NOTHROW(t.relation("sara"));
  CHECK_NOTHROW(t.relation("yaakov"));
  CHECK_NOTHROW(t.relation("miriam"));
  CHECK_NOTHROW(t.relation("david"));
  CHECK_NOTHROW(t.relation("keren"));
  CHECK_NOTHROW(t.relation("nisim"));
  CHECK_NOTHROW(t.relation("rivka"));
  CHECK(t.relation("yosef") == string("father"));
  CHECK(t.relation("hana") == string("mother"));
  CHECK(t.relation("yitzhak") == string("grandfather"));
  CHECK(t.relation("sara") == string("grandmother"));
  CHECK(t.relation("yaakov") == string("great-grandfather"));
  CHECK(t.relation("miriam") == string("great-grandmother"));
  CHECK(t.relation("david") == string("great-great-grandfather"));
  CHECK(t.relation("keren") == string("great-great-grandmother"));
  CHECK(t.relation("nisim") == string("great-great-great-grandfather"));
  CHECK(t.relation("rivka") == string("great-great-great-grandmother"));
  CHECK(t.relation("moshe") == string("unrelated"));
  CHECK(t.relation("hadas") == string("unrelated"));
  CHECK(t.relation("yoyo") == string("unrelated"));
  CHECK(t.relation("jojo") == string("unrelated"));
  CHECK(t.relation("ori") == string("me"));
}

TEST_CASE("Test remove")
{
  family::Tree t("ori");
  t.addFather("ori", "yosef");
  t.addMother("ori", "hana");
  t.addFather("yosef", "yitzhak");
  t.addMother("yosef", "sara");
  t.addFather("yitzhak", "yaakov");
  t.addMother("yitzhak", "miriam");
  t.addFather("yaakov", "david");
  t.addMother("yaakov", "keren");
  t.addFather("david", "nisim");
  t.addMother("david", "rivka");
  CHECK_NOTHROW(t.relation("ori"));
  CHECK_NOTHROW(t.relation("yosef"));
  CHECK_NOTHROW(t.relation("hana"));
  CHECK_NOTHROW(t.relation("yitzhak"));
  CHECK_NOTHROW(t.relation("sara"));
  CHECK_NOTHROW(t.relation("yaakov"));
  CHECK_NOTHROW(t.relation("miriam"));
  CHECK_NOTHROW(t.relation("david"));
  CHECK_NOTHROW(t.relation("keren"));
  CHECK_NOTHROW(t.relation("nisim"));
  CHECK_NOTHROW(t.relation("rivka"));

  t.remove("david");
  CHECK(t.relation("david") == string("unrelated"));
  CHECK(t.relation("nisim") == string("unrelated"));
  CHECK(t.relation("rivka") == string("unrelated"));
  t.remove("yosef");
  CHECK(t.relation("yosef") == string("unrelated"));
  CHECK(t.relation("yitzhak") == string("unrelated"));
  CHECK(t.relation("sara") == string("unrelated"));
  CHECK(t.relation("yaakov") == string("unrelated"));
  CHECK(t.relation("miriam") == string("unrelated"));
}

TEST_CASE("Test remove")
{
  family::Tree t("ori");
  t.addFather("ori", "yosef");
  t.addMother("ori", "hana");
  t.addFather("yosef", "yitzhak");
  t.addMother("yosef", "sara");
  t.addFather("yitzhak", "yaakov");
  t.addMother("yitzhak", "miriam");
  t.addFather("yaakov", "david");
  t.addMother("yaakov", "keren");
  t.addFather("david", "nisim");
  t.addMother("david", "rivka");
  t.remove("david");
  CHECK_THROWS(t.relation("david"));
  CHECK_THROWS(t.relation("nisim"));
  CHECK_THROWS(t.relation("rivka"));
  t.remove("yosef");
  CHECK_THROWS(t.relation("yosef"));
  CHECK_THROWS(t.relation("yitzhak"));
  CHECK_THROWS(t.relation("sara"));
  CHECK_THROWS(t.relation("yaakov"));
  CHECK_THROWS(t.relation("miriam"));
}

TEST_CASE("father already exist- throw exeption")
{
  family::Tree t("ori");
  t.addFather("ori", "yosef");
  CHECK_THROWS(t.addFather("ori", "moshe"));
}


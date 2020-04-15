
#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

TEST_CASE("Test addFather")
{
  family::Tree t ("ori");
  t.addFather("ori", "yosef");
  t.addFather("yosef", "yitzhak");
  t.addFather("yitzhak", "yaakov");
  t.addFather("yaakov", "david");
  t.addFather("david", "nisim");
  person * root = t.get_root();
  CHECK((root->father)->name == string("yosef"));
  CHECK(root->father->father->name == string("yitzhak"));
  CHECK(root->father->father->father->name == string("yaakov"));
  CHECK(root->father->father->father->father->name == string("david"));
  CHECK(root->father->father->father->father->father->name == string("nisim"));
}

TEST_CASE("Test addMother")
{
  family::Tree t ("ori");
  t.addMother("ori", "hana");
  t.addMother("hana", "sara");
  t.addMother("sara", "miriam");
  t.addMother("miriam", "rivka");
  t.addMother("rivka", "hadas");
  person * root = t.get_root();
  CHECK((root->mother)->name == string("hana"));
  CHECK(root->mother->mother->name == string("sara"));
  CHECK(root->mother->mother->mother->name == string("miriam"));
  CHECK(root->mother->mother->mother->mother->name == string("rivka"));
  CHECK(root->mother->mother->mother->mother->mother->name == string("hadas"));
}

TEST_CASE("Test relation")
{
  family::Tree t ("ori");
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

TEST_CASE("Test find")
{
family::Tree t ("ori");
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

TEST_CASE("Test remove")
{
  family::Tree t ("ori");
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

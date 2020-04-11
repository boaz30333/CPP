
#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

TEST_CASE("")
{

}

TEST_CASE("Test exception throwing")
{
    CHECK_THROWS(find("schoolhouse", "school")); // contain

}

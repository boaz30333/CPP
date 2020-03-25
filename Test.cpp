#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


TEST_CASE("Test replacement of lower-case and upper-case first word") { // 7 checks
    string text = "Happi xxx yyy";
    CHECK(find(text, "HappI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HapPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HAPpI") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "happi") == string("Happi"));
}
TEST_CASE("Test replacement of lower-case and upper-case middle word") { // 7 checks
    string text = "xxx Happi yyy";
    CHECK(find(text, "HappI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HapPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HAPpI") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "happi") == string("Happi"));
}
TEST_CASE("Test replacement of lower-case and upper-case end word") { // 7 checks
    string text = "xxx yyy Happi";
    CHECK(find(text, "HappI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HapPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HAPpI") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "happi") == string("Happi"));
}
///////////////

TEST_CASE("Test replacement of s and z - first word word") { // 4 checks
    string text = "sizes xxx yyy";
    CHECK(find(text, "zizes") == string("sizes"));
    CHECK(find(text, "zises") == string("sizes"));
    CHECK(find(text, "sises") == string("sizes"));
    CHECK(find(text, "sizez") == string("sizes"));
}
TEST_CASE("Test replacement of p and b - middle word") { // 4 checks
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of d and t - end word") { // 3 checks
    string text = "xxx yyy dontodent";
    CHECK(find(text, "dontodent") == string("dontodent"));
    CHECK(find(text, "tontodent") == string("dontodent"));
    CHECK(find(text, "dondodent") == string("dontodent"));
}

/////

TEST_CASE("Test replacement of w and v and uper-lower cases middle word") { // 6 checks
    string text = "xxx wave yyy";
    CHECK(find(text, "wave") == string("wave"));
    CHECK(find(text, "vave") == string("wave"));
    CHECK(find(text, "Wave") == string("wave"));
    CHECK(find(text, "vaVe") == string("wave"));
    CHECK(find(text, "vaWe") == string("wave"));
    CHECK(find(text, "vaVe") == string("wave"));
}
TEST_CASE("Test replacement of w and v and uper-lower cases first word") { // 6 checks
    string text = "wave xxx yyy";
    CHECK(find(text, "wave") == string("wave"));
    CHECK(find(text, "vave") == string("wave"));
    CHECK(find(text, "Wave") == string("wave"));
    CHECK(find(text, "vaVe") == string("wave"));
    CHECK(find(text, "vaWe") == string("wave"));
    CHECK(find(text, "vaVe") == string("wave"));
}
TEST_CASE("Test replacement of w and v and uper-lower cases end word") { // 6 checks
    string text = "xxx yyy wave";
    CHECK(find(text, "wave") == string("wave"));
    CHECK(find(text, "vave") == string("wave"));
    CHECK(find(text, "Wave") == string("wave"));
    CHECK(find(text, "vaVe") == string("wave"));
    CHECK(find(text, "vaWe") == string("wave"));
    CHECK(find(text, "vaVe") == string("wave"));
}
/////////////
TEST_CASE("Test replacement of c and k and q") { // 8 checks
    string text = "quick cmake cqk";
    CHECK(find(text, "quick") == string("quick"));
    CHECK(find(text, "Cuick") == string("quick"));
    CHECK(find(text, "kuicQ") == string("quick"));
    CHECK(find(text, "quiKc") == string("quick"));
    CHECK(find(text, "qmace") == string("cmake"));
    CHECK(find(text, "cmace") == string("cmake"));
    CHECK(find(text, "ckq") == string("cqk"));
    CHECK(find(text, "kcq") == string("cqk"));
}


TEST_CASE("Test replacement of g and j and uper-lower cases") { // 6 checks
    string text = "jump xxx judge";
    CHECK(find(text, "Gump") == string("jump"));
    CHECK(find(text, "Jump") == string("jump"));
    CHECK(find(text, "jump") == string("jump"));
    CHECK(find(text, "judge") == string("judge"));
    CHECK(find(text, "gudge") == string("judge"));
    CHECK(find(text, "judje") == string("judge"));
}
TEST_CASE("Test replacement of f and b and uper-lower cases") { // 4 checks
    string text = "find the buf buffer";
    CHECK(find(text, "Bind") == string("find"));
    CHECK(find(text, "BUB") == string("buf"));
    CHECK(find(text, "fuffer") == string("buffer"));
    CHECK(find(text, "BufBer") == string("buffer"));
}
TEST_CASE("Test exception throwing") { // 16 checks
    CHECK_THROWS(find("schoolhouse", "school"));
    CHECK_THROWS(find("schoolhouse", "house"));
    CHECK_THROWS(find("armchair", "arm"));
    CHECK_THROWS(find("armchair", "chair"));
    CHECK_THROWS(find("backyard", "back"));
    CHECK_THROWS(find("backyard", "yard"));
    CHECK_THROWS(find("housewife", "house"));
    CHECK_THROWS(find("housewife", "wife")); 
    CHECK_THROWS(find("schoolbook", "school"));
    CHECK_THROWS(find("schoolbook", "book")); 
    CHECK_THROWS(find("houseplant", "house"));
    CHECK_THROWS(find("houseplant", "plant"));
    CHECK_THROWS(find("flowerpot", "flower"));
    CHECK_THROWS(find("flowerpot", "pot"));
    CHECK_THROWS(find("neighborhood", "neighbor"));
    CHECK_THROWS(find("neighborhood", "hood"));
    CHECK_THROWS(find("ori ben hamo", ""));
    CHECK_THROWS(find("ori ben hamo", " "));
    CHECK_THROWS(find("neighborhood", "neighbor"));
    CHECK_THROWS(find("neighborhood", "hood"));
    CHECK_THROWS(find("neighborhood", "neighbor"));
    CHECK_THROWS(find("neighborhood", "hood"));
    CHECK_THROWS(find("neighborhood", "neighbor"));
    CHECK_THROWS(find("neighborhood", "hood"));
    CHECK_THROWS(find("neighborhood", "neighbor"));
    CHECK_THROWS(find("neighborhood", "hood"));
    CHECK_THROWS(find("neighborhood", "neighbor"));
    CHECK_THROWS(find("neighborhood", "hood"));
    CHECK_THROWS(find("neighborhood", "neighbor"));
    CHECK_THROWS(find("neighborhood", "hood"));
}
/* Add more test cases here */
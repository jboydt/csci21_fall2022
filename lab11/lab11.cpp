//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "slist.h"

#include <cstdlib> // srand, rand
#include <ctime>   // time

TEST_CASE("singly-linked list") {

  SList list;

  SUBCASE("empty list") {
    CHECK_EQ(list.empty(), true);
    CHECK_EQ(list.getSize(), 0);
    CHECK_EQ(list.toString(), string(""));
    CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
    CHECK_THROWS_WITH_AS(list.popFront(), "EMPTY LIST", logic_error);
  }

  SUBCASE("minimally populated list") {
    for (int i = 50; i >= -50; i -= 10) {
      list.pushFront(i);
    }

    CHECK_EQ(list.empty(), false);
    CHECK_EQ(list.getSize(), 11);
    CHECK_EQ(list.toString(), string("-50,-40,-30,-20,-10,0,10,20,30,40,50"));
    CHECK_EQ(list.front(), -50);
    list.popFront();
    CHECK_EQ(list.front(), -40);
    list.popFront();
    CHECK_EQ(list.front(), -30);
    list.popFront();
    CHECK_EQ(list.front(), -20);
    list.popFront();
    CHECK_EQ(list.front(), -10);
    list.popFront();

    CHECK_EQ(list.getSize(), 6);
    CHECK_EQ(list.toString(), string("0,10,20,30,40,50"));

    list.clear();
    CHECK_EQ(list.empty(), true);
    CHECK_EQ(list.getSize(), 0);
    CHECK_EQ(list.toString(), "");
    CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
    CHECK_THROWS_WITH_AS(list.popFront(), "EMPTY LIST", logic_error);
  }

  SUBCASE("stress test") {
    srand(time(nullptr));

    for (unsigned int i = 0; i < 1000; i++) {
      list.pushFront(rand() % 1000);
    }

    for (unsigned int i = 0; i < 500; i++) {
      list.popFront();
    }

    CHECK_EQ(list.getSize(), 500);

    list.clear();
    CHECK_EQ(list.empty(), true);
    CHECK_EQ(list.getSize(), 0);
    CHECK_EQ(list.toString(), "");
    CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
    CHECK_THROWS_WITH_AS(list.popFront(), "EMPTY LIST", logic_error);
  }
}

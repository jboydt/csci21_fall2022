//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "slist.h"

/*
 * Unit test. Do not alter.
 */

TEST_CASE("Singly-linked list") {
  SList list;

  SUBCASE("empty list") {
    CHECK_EQ(list.empty(), true);
    CHECK_EQ(list.getSize(), 0);
    CHECK_EQ(list.toString(), string(""));
    CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
  }

  SUBCASE("minimally populated list") {
    for (int i = 50; i >= -50; i -= 10) {
      list.pushFront(i);
    }

    CHECK_EQ(list.empty(), false);
    CHECK_EQ(list.getSize(), 11);
    CHECK_EQ(list.toString(), string("-50,-40,-30,-20,-10,0,10,20,30,40,50"));
    CHECK_EQ(list.front(), -50);
  }
}

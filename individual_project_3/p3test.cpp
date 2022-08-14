//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "dllist.hpp"

/*
 * Unit test. Do not alter.
 */

TEST_CASE ("doubly-linked list") {

	SUBCASE("empty list (bool)") {
		DLList<bool> list;

		CHECK_EQ(list.empty(), true);
		CHECK_EQ(list.getSize(), 0);
		CHECK_EQ(list.toString(), "");
		CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
		CHECK_THROWS_WITH_AS(list.back(), "EMPTY LIST", logic_error);
		CHECK_THROWS_WITH_AS(list.popFront(), "EMPTY LIST", logic_error);
		CHECK_THROWS_WITH_AS(list.popBack(), "EMPTY LIST", logic_error);
		CHECK_EQ(list.get(true), false);
		CHECK_EQ(list.removeFirst(true), false);
		CHECK_EQ(list.removeAll(true), false);
	}

	SUBCASE("unsorted list (int32_t)") {
		DLList<int32_t> list;

		list.pushFront(-50);
		list.pushBack(50);
		list.pushFront(-40);
		list.pushBack(40);
		list.pushFront(-30);
		list.pushBack(30);
		list.pushFront(-20);
		list.pushBack(20);
		list.pushFront(-10);
		list.pushBack(10);

		CHECK_EQ(list.empty(), false);
		CHECK_EQ(list.getSize(), 10);
		CHECK_EQ(list.toString(), "-10,-20,-30,-40,-50,50,40,30,20,10");
		CHECK_EQ(list.front(), -10);
		CHECK_EQ(list.back(), 10);

		list.pushFront(20);
		CHECK_EQ(list.getSize(), 11);
		CHECK_EQ(list.toString(), "20,-10,-20,-30,-40,-50,50,40,30,20,10");
		CHECK_EQ(list.front(), 20);
		CHECK_EQ(list.removeFirst(20), true);
		CHECK_EQ(list.getSize(), 10);
		CHECK_EQ(list.toString(), "-10,-20,-30,-40,-50,50,40,30,20,10");
		CHECK_EQ(list.front(), -10);

		list.pushFront(20);
		list.pushFront(20);
		CHECK_EQ(list.getSize(), 12);
		CHECK_EQ(list.toString(), "20,20,-10,-20,-30,-40,-50,50,40,30,20,10");
		CHECK_EQ(list.removeAll(20), true);
		CHECK_EQ(list.getSize(), 9);
		CHECK_EQ(list.toString(), "-10,-20,-30,-40,-50,50,40,30,10");

		list.clear();

		CHECK_EQ(list.empty(), true);
		CHECK_EQ(list.getSize(), 0);
		CHECK_EQ(list.toString(), "");
		CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
		CHECK_THROWS_WITH_AS(list.back(), "EMPTY LIST", logic_error);
		CHECK_THROWS_WITH_AS(list.popFront(), "EMPTY LIST", logic_error);
		CHECK_THROWS_WITH_AS(list.popBack(), "EMPTY LIST", logic_error);
		CHECK_EQ(list.get(true), false);
		CHECK_EQ(list.removeFirst(true), false);
		CHECK_EQ(list.removeAll(true), false);
	}

	SUBCASE("sorted list (int32_t)") {
		DLList<int32_t> list;

		for (int32_t i=50; i>0; i-=10) {
			list.insert(-i);
			list.insert(i);
		}

		CHECK_EQ(list.empty(), false);
		CHECK_EQ(list.getSize(), 10);
		CHECK_EQ(list.toString(), "-50,-40,-30,-20,-10,10,20,30,40,50");
		CHECK_EQ(list.front(), -50);
		CHECK_EQ(list.back(), 50);

		list.insert(20);
		CHECK_EQ(list.getSize(), 11);
		CHECK_EQ(list.toString(), "-50,-40,-30,-20,-10,10,20,20,30,40,50");
		CHECK_EQ(list.removeFirst(20), true);
		CHECK_EQ(list.getSize(), 10);
		CHECK_EQ(list.toString(), "-50,-40,-30,-20,-10,10,20,30,40,50");

		list.insert(20);
		list.insert(20);
		CHECK_EQ(list.getSize(), 12);
		CHECK_EQ(list.toString(), "-50,-40,-30,-20,-10,10,20,20,20,30,40,50");
		CHECK_EQ(list.removeAll(20), true);
		CHECK_EQ(list.getSize(), 9);
		CHECK_EQ(list.toString(), "-50,-40,-30,-20,-10,10,30,40,50");

		list.popFront();
		list.popBack();
		CHECK_EQ(list.getSize(), 7);
		CHECK_EQ(list.toString(), "-40,-30,-20,-10,10,30,40");

		list.popFront();
		list.popBack();
		CHECK_EQ(list.getSize(), 5);
		CHECK_EQ(list.toString(), "-30,-20,-10,10,30");

		list.popFront();
		list.popBack();
		CHECK_EQ(list.getSize(), 3);
		CHECK_EQ(list.toString(), "-20,-10,10");

		list.popFront();
		list.popBack();
		CHECK_EQ(list.getSize(), 1);
		CHECK_EQ(list.toString(), "-10");
		CHECK_EQ(list.front(), -10);
		CHECK_EQ(list.back(), -10);

		list.clear();

		CHECK_EQ(list.empty(), true);
		CHECK_EQ(list.getSize(), 0);
		CHECK_EQ(list.toString(), "");
		CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
		CHECK_THROWS_WITH_AS(list.back(), "EMPTY LIST", logic_error);
		CHECK_THROWS_WITH_AS(list.popFront(), "EMPTY LIST", logic_error);
		CHECK_THROWS_WITH_AS(list.popBack(), "EMPTY LIST", logic_error);
		CHECK_EQ(list.get(true), false);
		CHECK_EQ(list.removeFirst(true), false);
		CHECK_EQ(list.removeAll(true), false);
	}
}

//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "hash_table.h"

#include <array>
#include <sstream>
using std::array;
using std::ostringstream;

TEST_CASE ("hash function and hash table functionality") {
	array<Item, 15> items = {
	    Item("apple"),
	    Item("banana"),
	    Item("grape"),
	    Item("lemon"),
	    Item("melon"),
	    Item("orange"),
	    Item("strawberry"),
	    Item("pear"),
	    Item("blueberry"),
	    Item("grapefruit"),
	    Item("apple"),
	    Item("banana"),
	    Item("grape"),
	    Item("lemon"),
	    Item("melon")
	};
	HashTable ht;

	CHECK_EQ(ht.size(), 0);
	CHECK_EQ(ht.toString(),
		string("Items in hash table: 0\n[0]\t\n[1]\t\n[2]\t\n[3]\t\n[4]\t\n"));

	CHECK_EQ(ht.hash(items[0]), 0);
	CHECK_EQ(ht.hash(items[4]), 4);
	CHECK_EQ(ht.hash(items[8]), 2);
	CHECK_EQ(ht.hash(items[12]), 2);
	CHECK_EQ(ht.hash(items[14]), 4);

	for (Item i : items) {
		ht.insert(i);
	}

	CHECK_EQ(ht.size(), 10);

	ostringstream output;
	output << "Items in hash table: 10\n" << "[0]\t     apple (2) \n";
	output << "[1]\t    orange (1) grapefruit (1) \n" << "[2]\t     grape (2)  blueberry (1) \n";
	output << "[3]\t\n";
	output << "[4]\t    banana (2)      lemon (2)      melon (2) strawberry (1)       pear (1) \n";
	CHECK_EQ(ht.toString(), output.str());

	Item* tempItem = ht.getItem("shoe");
	CHECK_EQ(tempItem, nullptr);

	tempItem = ht.getItem("apple");
	CHECK_NE(tempItem, nullptr);
	CHECK_EQ(tempItem->count, 2);

	tempItem = ht.getItem("pear");
	CHECK_NE(tempItem, nullptr);
	CHECK_EQ(tempItem->count, 1);

	CHECK_EQ(ht.remove("shoe"), false);

	CHECK_EQ(ht.remove("apple"), true);
	CHECK_EQ(ht.size(), 9);

	CHECK_EQ(ht.remove("apple"), false);

	CHECK_EQ(ht.remove("orange"), true);
	CHECK_EQ(ht.remove("grapefruit"), true);
	CHECK_EQ(ht.remove("grape"), true);
	CHECK_EQ(ht.remove("blueberry"), true);
	CHECK_EQ(ht.remove("banana"), true);
	CHECK_EQ(ht.remove("lemon"), true);
	CHECK_EQ(ht.remove("melon"), true);
	CHECK_EQ(ht.remove("strawberry"), true);
	CHECK_EQ(ht.remove("pear"), true);

	CHECK_EQ(ht.size(), 0);
}

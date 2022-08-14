// ASSIGNMENT NAME
// PROGRAMMER NAME
//
// DATE
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using std::invalid_argument;
using std::ios;
using std::string;
using std::ostringstream;

// Allocate memory for a string containing given contents.
// Return a pointer to the allocated string.
string* makeDynamicString (string contents) {

}

// Free the memory associated with a string and null the pointer.
// Throws std::invalid_argument("NULL STRING POINTER") if theString is nullptr.
void clearDynamicString (string*& theString) noexcept(false) {

}

// Return the length of theString. Populate "alpha" with the number
// of alphabetic characters in theString. Populate "num" with the number
// of numeric characters in theString.
// Throws std::invalid_argument("NULL STRING POINTER") if theString is nullptr.
unsigned int countChars (string* theString, unsigned int& alpha, unsigned int& num) noexcept(false) {

}

// Return true if theWord is found in theString. Return false otherwise.
// Throws std::invalid_argument("NULL STRING POINTER") if theString is nullptr.
bool findWord (string* theString, string theWord) noexcept(false) {

}

// Replace oldWord with newWord in theString. If oldWord is not present, theString
// remains unaltered. Return true if the string has been altered. Return false
// otherwise. Case-sensitive.
//
// EXAMPLES:
//
// given -> theString="I like grapes.", oldWord="grapes", newWord="apples"
// on return -> theString="I like apples."
//
// Throws std::invalid_argument("NULL STRING POINTER") if theString is nullptr.
bool replaceWord (string* theString, string oldWord, string newWord) noexcept(false) {

}

////////////////////////////////////////////////

struct Item {
	string name;
	float price;
	unsigned int quantity;

	Item(string name, float price, unsigned int quantity) {
		this->name = name;
		this->price = price;
		this->quantity = quantity;
	}
};

// Allocate memory for a dynamic Item, populated with the given data.
// Return a pointer to the newly allocated Item.
Item* makeDynamicItem (string newName, float newPrice, unsigned int newQuantity) {

}

// Free the memory associated with a dynamic Item and null the pointer.
// Throws std::invalid_argument("NULL ITEM POINTER") if item is nullptr.
void clearDynamicItem (Item*& item) noexcept(false) {

}

// Update an Item with a new name, price, and quantity.
// Throws std::invalid_argument("NULL ITEM POINTER") if item is nullptr.
void updateItem (Item* item, string newName, float newPrice, unsigned int newQuantity) noexcept(false) {

}

// Return the price to purchase an Item (Item quantity * Item price).
// Throws std::invalid_argument("NULL ITEM POINTER") if item is nullptr.
float calculatePurchasePrice (Item* item) noexcept(false) {

}

// Return a string representation of an Item.
//
// EXAMPLE: "book, 3 @ $5.99"
//
// Throws std::invalid_argument("NULL ITEM POINTER") if item is nullptr.
string toString (Item* item) noexcept(false) {

}

//
// Unit test. Do not alter.
//

TEST_CASE("dynamic string") {

	string* myString = nullptr;
	unsigned int alpha, num;

	CHECK_THROWS_WITH_AS(countChars(myString, alpha, num), "NULL STRING POINTER", invalid_argument);
	CHECK_THROWS_WITH_AS(findWord(myString, "hello"), "NULL STRING POINTER", invalid_argument);
	CHECK_THROWS_WITH_AS(replaceWord(myString, "hello", "goodbye"), "NULL STRING POINTER", invalid_argument);

	myString = makeDynamicString("123, abc; 456: hello. 0!");
	CHECK_NE(myString, nullptr);
	CHECK_EQ(countChars(myString, alpha, num), 24);
	CHECK_EQ(alpha, 8);
	CHECK_EQ(num, 7);
	CHECK_EQ(findWord(myString, "HELLO"), false);
	CHECK_EQ(findWord(myString, "abc"), true);

	CHECK_EQ(replaceWord(myString, "hello", "goodbye"), true);
	CHECK_EQ(*myString, string("123, abc; 456: goodbye. 0!"));
	CHECK_EQ(replaceWord(myString, "GOODBYE", "HELLO"), false);

	clearDynamicString(myString);
	CHECK_THROWS_WITH_AS(clearDynamicString(myString), "NULL STRING POINTER", invalid_argument);
}

TEST_CASE("dynamic item") {
	Item *item = nullptr;

  CHECK_THROWS_WITH_AS(clearDynamicItem(item), "NULL ITEM POINTER", invalid_argument);
  CHECK_THROWS_WITH_AS(updateItem(item, "", 0, 0.0f), "NULL ITEM POINTER", invalid_argument);
  CHECK_THROWS_WITH_AS(calculatePurchasePrice(item), "NULL ITEM POINTER", invalid_argument);
  CHECK_THROWS_WITH_AS(toString(item), "NULL ITEM POINTER", invalid_argument);

  item = makeDynamicItem("no name", 0.0, 0);

	CHECK_EQ(toString(item), string("no name, 0 @ $0.00"));

	updateItem(item, "apples", 0.25f, 5);
	CHECK_EQ(item->name, string("apples"));
	CHECK_EQ(item->price, doctest::Approx(0.25f));
	CHECK_EQ(item->quantity, 5);
	CHECK_EQ(toString(item), string("apples, 5 @ $0.25"));
	CHECK_EQ(calculatePurchasePrice(item), doctest::Approx(1.25f));

	clearDynamicItem(item);
	CHECK_THROWS_WITH_AS(toString(item), "NULL ITEM POINTER", invalid_argument);
}

// ASSIGNMENT NAME
// PROGRAMMER NAME
//
// DATE
 #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
 #include "doctest.h"

#include <sstream>
#include <string>
using std::ios;
using std::string;
using std::ostringstream;

struct Item {
  string name;
  double price;
  unsigned int quantity;
};

// Initialize an Item with values for its fields.
void initItem(Item &i, string name, double price, unsigned int quantity) {}

// Compute the total value of an item (price * quantity)
double totalValue(const Item &i) { return 0.0; }

// Reduce the quantity of an Item by a specified amount.
// If amount > Item.quantity, set Item.quantity to 0.
void reduceQuantity(Item &i, unsigned int amount) {}

// Increase the quantity of an Item by a specified amount.
void increaseQuantity(Item &i, unsigned int amount) {}

// Example: "Apples (price: $0.99, quantity: 3)"
// Use the "magic formula" to format the price.
string toString(const Item &i) {
  ostringstream out;

  return out.str();
}

//
// Unit test. Do not alter.
//

 TEST_CASE("struct and helper functions") {
   Item item;

   initItem(item, "Apples", 0.9, 3);
   CHECK_EQ(item.name, "Apples");
   CHECK_EQ(item.price, doctest::Approx(0.9));
   CHECK_EQ(item.quantity, 3);
   CHECK_EQ(totalValue(item), doctest::Approx(2.7));
   CHECK_EQ(toString(item), string("Apples (price: $0.90, quantity: 3)"));

   reduceQuantity(item, 2);
   CHECK_EQ(item.quantity, 1);

   reduceQuantity(item, 2);
   CHECK_EQ(item.quantity, 0);
   CHECK_EQ(totalValue(item), doctest::Approx(0.0));
   CHECK_EQ(toString(item), string("Apples (price: $0.90, quantity: 0)"));

   increaseQuantity(item, 10);
   CHECK_EQ(item.quantity, 10);
   CHECK_EQ(totalValue(item), doctest::Approx(9.0));
   CHECK_EQ(toString(item), string("Apples (price: $0.90, quantity: 10)"));
 }

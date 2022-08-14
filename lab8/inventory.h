// ASSIGNMENT NAME
// PROGRAMMER NAME
//
// DATE
#pragma once

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using std::ios;
using std::ostringstream;
using std::sort;
using std::string;
using std::vector;

struct Item {
  string name;
  float price;
  unsigned int quantity;
};

// Returns true if i1.name comes before (lexicographicall) i2.name, otherwise
// returns false
bool compareByName(const Item& i1, const Item& i2);

// Returns true if i1.price comes before (is less than) i2.price, otherwise
// returns false
bool compareByPrice(const Item& i1, const Item& i2);

// Returns true if i1.quantity comes before (is less than) i2.quantity, otherwise
// returns false
bool compareByQuantity(const Item& i1, const Item& i2);

// Return a string representation of an Item
//
// EX: NAME, $PRICE, QUANTITY available
//     apple, $0.75, 3 available
string itemToString(const Item& i);

class Inventory {
public:
  // Add an Item to the Inventory
  // Return true if the Item is not already in the inventory
  // and has been added
  // Return false if this item name duplicates an Item already
  // in inventory
  bool addItem(Item i);

  // Remove an Item, by name, from the inventory
  // Return true if the Item is present and has been removed, false otherwise
  bool removeItem(string name);

  // Update an Item in the Inventory
  // Return true if the Item is present and has been updated with
  // the new values, false otherwise
  bool updateItem(string oldName, string newName, float newPrice, unsigned int newQuantity);

  // Return true if the Item, by name, is in the inventory, false otherwise
  bool hasItem(string name);

  // Return the number of items in the inventory
  unsigned int getItemCount();

  // Clear all of the items from the inventory
  void clear();

  // Sort the inventory by item name, using std::sort and compareByName function
  void sortByName();

  // Sort the inventory by item price, using std::sort and compareByPrice function
  void sortByPrice();

  // Sort the inventory by item quantity, using std::sort and compareByQuantity function
  void sortByQuantity();

  // Return a string representation of the inventory
  //   (return empty string if inventory is empty)
  // Use the itemToString function on each item
  // Start the numbering from 1
  //
  // EX: [NUMBER] itemToString(ITEM)
  //
  //     [1] apple, $0.75, 3 available
  //     [2] grapefruit, $1.50, 2 available
  //     [3] orange, $0.99, 5 available
  //
  string toString();

private:
  vector<Item> inventory;
};

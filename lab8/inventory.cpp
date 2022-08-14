#include "inventory.h"

// ITEM FUNCTIONS

bool compareByName(const Item& i1, const Item& i2) {

}

bool compareByPrice(const Item& i1, const Item& i2) {

}

bool compareByQuantity(const Item& i1, const Item& i2) {

}

// This function has already been implemented.
string itemToString(const Item& i) {
  ostringstream out;
  out.setf(ios::fixed);
  out.setf(ios::showpoint);
  out.precision(2);
  out << i.name << ", $" << i.price << ", " << i.quantity << " available";
  return out.str();
}

// INVENTORY FUNCTIONS

bool Inventory::addItem(Item i) {

}

bool Inventory::removeItem(string name) {

}

bool Inventory::updateItem(string oldName, string newName, float newPrice, unsigned int newQuantity) {

}

bool Inventory::hasItem(string name) {

}

unsigned int Inventory::getItemCount() {

}

void Inventory::clear() {

}

void Inventory::sortByName() {

}

void Inventory::sortByPrice() {

}

void Inventory::sortByQuantity() {

}

string Inventory::toString() {

}

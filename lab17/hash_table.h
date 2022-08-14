// ASSIGNMENT NAME
// PROGRAMMER NAME
//
// DATE
#pragma once

#include <array>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::array;
using std::endl;
using std::ostringstream;
using std::setw;
using std::string;
using std::vector;

// An Item to be stored in a HashTable.
struct Item {
  // Overloaded constructor for convenience
	Item (string newContents) : count(1), contents(newContents) {}

	unsigned int count;
	string contents;
};

class HashTable {
	public:

		// Insert an item into the hash table
		// If the Item (by its contents) is already in the hash table,
		// increment the count of the Item already in the hash table --
		// do not insert duplicates
		void insert(Item i);

		// Remove an item from the hash table
		// Return true if an Item with the contents was removed, false otherwise
		bool remove(string contents);

		// Return a pointer to an Item in the hash table, by contents
		// Return nullptr if no Item matches the contents
		Item* getItem(string contents);

		// Return the number of items currently stored in the hash table
		unsigned int size();

		// Return the key for an Item object
    // Uses the string contents member of Item to compute the key;
    // uses the private hash function on string contents
		unsigned int hash(Item i);

		// Return a string representation of the hash table
    //
    // FORMAT/TEMPLATE:
		//
		// Items in hash table: hash_table_size
		// [array_index]<TAB>contents (count) contents (count) ...REST OF BUCKET
		//
		// NOTE: insert a TAB character after [array_index] and output
    //       item_contents into a field of width 10 (using setw)
		//
		// EXAMPLES:
		//
		// Items in hash table: 0
		// [0]<TAB>
		// [1]<TAB>
		// [2]<TAB>
		// [3]<TAB>
		// [4]<TAB>
		//
		// Items in hash table: 4
		// [0]<TAB>apple (1) banana (2)
		// [1]<TAB>
		// [2]<TAB>blueberry (1)
		// [3]<TAB>
		// [4]<TAB>pear (1)
		string toString();

	private:
		// This is the hash table data structure.
		array<vector<Item>, 5> items;

		// Return a key based on a string
    //
		// Compute a key (unsigned integer) by summing the ASCII values
		// of the characters in a string and modding the sum to fit the
    // std::array size.
		unsigned int hash (string s);
};

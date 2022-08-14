//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "bstree.hpp"
#include "word.h"

#include <iostream>
#include <sstream>
using std::cout;
using std::ostringstream;
using std::streambuf;

TEST_CASE ("Word class") {

	Word word1;
	Word word2("apple");
	Word word3("banana");

	ostringstream outs;

	SUBCASE("Default constructor") {

		CHECK_EQ(word1.getWord(), "");
		CHECK_EQ(word1.getCount(), 1);

		outs << word1;
		CHECK_EQ(outs.str(), string(" 1"));
		outs.str("");

		word1.setWord("apple");
		CHECK_EQ(word1.getWord(), string("APPLE"));

		word1.incrementCount();
		CHECK_EQ(word1.getCount(), 2);

		outs << word1;
		CHECK_EQ(outs.str(), string("APPLE 2"));
	}

	SUBCASE("Overloaded constructor") {

		CHECK_EQ(word2.getWord(), string("APPLE"));
		CHECK_EQ(word2.getCount(), 1);

		outs << word2;
		CHECK_EQ(outs.str(), string("APPLE 1"));
	}

	SUBCASE("Overloaded operators") {

		CHECK_LT(word2, word3);
		CHECK_GT(word3, word2);

		word3.setWord("apple");

		CHECK_EQ(word2, word3);
	}
}

TEST_CASE("Binary Search Tree (Word)") {
	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;

	BSTree<Word> tree;

	tree.insert(Word("banana"));
	tree.insert(Word("apple"));
	tree.insert(Word("orange"));

	CHECK_EQ(tree.getSize(), 3);

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.printInOrder();
	cout.rdbuf(oldCout);
	CHECK_EQ(captureCout.str(), string("APPLE 1\nBANANA 1\nORANGE 1\n"));

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.printReverseOrder();
	cout.rdbuf(oldCout);
	CHECK_EQ(captureCout.str(), string("ORANGE 1\nBANANA 1\nAPPLE 1\n"));

	Word* w = tree.get(Word("apple"));
	w->incrementCount();
	w->incrementCount();

	w = tree.get(Word("orange"));
	w->incrementCount();

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.printInOrder();
	cout.rdbuf(oldCout);
	CHECK_EQ(captureCout.str(), string("APPLE 3\nBANANA 1\nORANGE 2\n"));

	CHECK_EQ(tree.insert(Word("apple")), false);
}

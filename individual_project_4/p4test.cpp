//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "word.h"
#include "bstree.hpp"

#include <iostream>
#include <sstream>
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

TEST_CASE("Binary Search Tree (int)") {

	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;
	BSTree<int> tree;

	SUBCASE("BSTree<int> -- EMPTY") {

		CHECK_EQ(tree.getSize(), 0);
		CHECK_EQ(tree.find(1), false);
		CHECK_EQ(tree.get(1), nullptr);
		CHECK_EQ(tree.remove(1), false);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string(""));

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string(""));
	}

	SUBCASE("BSTree<int> -- ONE ITEM") {

		CHECK_EQ(tree.insert(100), true);

		CHECK_EQ(tree.getSize(), 1);
		CHECK_EQ(tree.find(100), true);

		int* t = tree.get(100);
		CHECK_NE(t, nullptr);
		CHECK_EQ(*t, 100);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);

		CHECK_EQ(captureCout.str(), string("100\n"));

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string("100\n"));

		CHECK_EQ(tree.insert(100), false);

		CHECK_EQ(tree.remove(100), true);
		CHECK_EQ(tree.getSize(), 0);
		CHECK_EQ(tree.find(100), false);
		CHECK_EQ(tree.get(100), nullptr);
		CHECK_EQ(tree.remove(100), false);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string(""));

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string(""));
	}

	SUBCASE("BSTree<int> -- MULTIPLE ITEMS") {

		tree.insert(100);
		tree.insert(50);
		tree.insert(150);
		tree.insert(25);
		tree.insert(75);
		tree.insert(125);
		tree.insert(175);

		CHECK_EQ(tree.getSize(), 7);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string("25\n50\n75\n100\n125\n150\n175\n"));

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string("175\n150\n125\n100\n75\n50\n25\n"));

		CHECK_EQ(tree.insert(25), false);
		CHECK_EQ(tree.insert(50), false);
		CHECK_EQ(tree.insert(75), false);
		CHECK_EQ(tree.insert(100), false);
		CHECK_EQ(tree.insert(125), false);
		CHECK_EQ(tree.insert(150), false);
		CHECK_EQ(tree.insert(175), false);
		CHECK_EQ(tree.getSize(), 7);

		CHECK_EQ(tree.remove(25), true);
		CHECK_EQ(tree.getSize(), 6);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string("50\n75\n100\n125\n150\n175\n"));

		CHECK_EQ(tree.remove(125), true);
		CHECK_EQ(tree.getSize(), 5);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string("175\n150\n100\n75\n50\n"));

		CHECK_EQ(tree.remove(100), true);
		CHECK_EQ(tree.getSize(), 4);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string("50\n75\n150\n175\n"));

		CHECK_EQ(tree.remove(75), true);
		CHECK_EQ(tree.getSize(), 3);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string("175\n150\n50\n"));

		CHECK_EQ(tree.remove(150), true);
		CHECK_EQ(tree.getSize(), 2);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string("50\n175\n"));

		CHECK_EQ(tree.remove(50), true);
		CHECK_EQ(tree.getSize(), 1);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string("175\n"));

		CHECK_EQ(tree.remove(50), false);
		CHECK_EQ(tree.find(50), false);
		CHECK_EQ(tree.get(50), nullptr);


		CHECK_EQ(tree.remove(175), true);
		CHECK_EQ(tree.getSize(), 0);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string(""));

		tree.insert(100);
		tree.insert(50);
		tree.insert(150);
		tree.insert(25);
		tree.insert(75);
		tree.insert(125);
		tree.insert(175);
		tree.clear();
		CHECK_EQ(tree.getSize(), 0);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK_EQ(captureCout.str(), string(""));
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

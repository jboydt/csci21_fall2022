// ASSIGNMENT NAME
// PROGRAMMER NAME
//
// DATE
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <sstream>
#include <string>
#include <vector>
using std::string;
using std::ostringstream;
using std::vector;

// Compute and return the factorial of value. 0 and 1 return 1.
// Recursive.
unsigned int factorial (unsigned int value) {

}

// Return the nth value of the Fibonacci sequence.
// Recursive.
unsigned int fibonacci (unsigned int nth) {

}

// Returns true if word is a palindrome. Returns false otherwise.
// Recursive.
bool wordIsPalindrome (string word) {

}

// Produces a string containing the contents of a vector, separated by single spaces,
// starting at a given index and going forward to the end of the vector.
// Recursive.
string vectorForwardsAsString (const vector<int>& v, unsigned int index) {

}

// Produces a string containing the contents of a vector, separated by single spaces,
// starting at a given index and going backward to the end of the vector.
// Recursive.
string vectorBackwardsAsString (const vector<int>& v, int startIndex) {

}

//
// Unit test. Do not alter.
//

TEST_CASE("recursive functions") {

	SUBCASE("recursive factorial function") {
		CHECK_EQ(factorial(0), 1);
		CHECK_EQ(factorial(1), 1);
		CHECK_EQ(factorial(2), 2);
		CHECK_EQ(factorial(5), 120);
	}

	SUBCASE("recursive fibonacci function") {
		CHECK_EQ(fibonacci(1), 1);
		CHECK_EQ(fibonacci(2), 1);
		CHECK_EQ(fibonacci(3), 2);
		CHECK_EQ(fibonacci(15), 610);
	}

	SUBCASE("recursive wordIsPalindrome function") {
		CHECK_EQ(wordIsPalindrome(""), true);
		CHECK_EQ(wordIsPalindrome("a"), true);
		CHECK_EQ(wordIsPalindrome("sitonapotatopanotis"), true);
		CHECK_EQ(wordIsPalindrome("baseball"), false);
	}
}

TEST_CASE("recursive vector to string functions") {
	vector<int> numbers = {5, 10, 15, 20, 25};

	SUBCASE("recursive vector forwards as string function") {
		CHECK_EQ(vectorForwardsAsString(numbers, 0), string("5 10 15 20 25 "));
		CHECK_EQ(vectorForwardsAsString(numbers, 3), string("20 25 "));
		CHECK_EQ(vectorForwardsAsString(numbers, 5), string(""));
	}

	SUBCASE("recursive vector backwards as string function") {
		CHECK_EQ(vectorBackwardsAsString(numbers, 4), string("25 20 15 10 5 "));
		CHECK_EQ(vectorBackwardsAsString(numbers, 1), string("10 5 "));
		CHECK_EQ(vectorBackwardsAsString(numbers, -1), string(""));
	}
}

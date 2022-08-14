//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "functions.h"

const string INPUT_FILE("wordlist.txt");

TEST_CASE("string processing") {
  SUBCASE("empty string") {
    CHECK_EQ(toupper(""), string(""));
    CHECK_EQ(tolower(""), string(""));
    CHECK_EQ(digits(""), 0);
    CHECK_EQ(punctuation(""), 0);
    CHECK_EQ(vowels(""), 0);
  }

  SUBCASE("simple strings") {
    CHECK_EQ(toupper("abc"), string("ABC"));
    CHECK_EQ(tolower("ABC"), string("abc"));
    CHECK_EQ(digits("123"), 3);
    CHECK_EQ(punctuation(",.;"), 3);
    CHECK_EQ(vowels("aeiou"), 5);
  }

  SUBCASE("harder strings") {
    CHECK_EQ(toupper("AbCd1.2,3;"), string("ABCD1.2,3;"));
    CHECK_EQ(tolower("AbCd1.2,3;"), string("abcd1.2,3;"));
    CHECK_EQ(digits("AbCd1.2,3;"), 3);
    CHECK_EQ(punctuation("AbCd1.2,3;"), 3);
    CHECK_EQ(vowels("AbCd1.2,3;"), 1);
  }
}

TEST_CASE("vector processing") {
  SUBCASE("empty file") {
    vector<string> vtest = readFile("nothere.txt");
    CHECK_EQ(vtest.size(), 0);
  }

  SUBCASE("wordlist file") {
    vector<string> vtest = readFile(INPUT_FILE);
    CHECK_EQ(vtest.size(), 50);
    CHECK_EQ(allCharacters(vtest), 376);
    CHECK_EQ(allDigits(vtest), 3);
    CHECK_EQ(allPunctuation(vtest), 3);
    CHECK_EQ(allVowels(vtest), 127);
  }
}

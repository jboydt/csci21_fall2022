// ASSIGNMENT NAME
// PROGRAMMER NAME
//
// DATE
 #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
 #include "doctest.h"

#include <string>
using std::string;

// COMPLETE EACH OF THE FOLLOWING FUNCTIONS

// Return a greeting: "Nice to meet you, NAME."
// If name param is empty string, return "Nice to meet you."
string greet(string name) {

}

// Return true if denominator is a factor of numerator.
// Return false otherwise.
bool isFactor(int numerator, int denominator) {

}

// Given an initial value, compute how many quarters, dimes, nickels, and
// pennies would be given as change.
void makeChange(unsigned int initialValue, unsigned int &quarters,
                unsigned int &dimes, unsigned int &nickels,
                unsigned int &pennies) {

}

// Convert a Celsius temperature to a Fahrenheit temperature.
double celsiusToFahrenheit(double celsiusTemp) {

}

// Convert a Fahrenheit temperature to a Celsius temperature.
double fahrenheitToCelsius(double fahrenheitTemp) {

}

//
// Unit test. Do not alter.
//

 TEST_CASE("Function implementations") {
   CHECK_EQ(greet(""), string("Nice to meet you."));
   CHECK_EQ(greet("Jane"), string("Nice to meet you, Jane."));

   CHECK_EQ(isFactor(100, 25), true);
   CHECK_EQ(isFactor(100, 24), false);

   unsigned int quarters, dimes, nickels, pennies;
   makeChange(41, quarters, dimes, nickels, pennies);
   CHECK_EQ(quarters, 1);
   CHECK_EQ(dimes, 1);
   CHECK_EQ(nickels, 1);
   CHECK_EQ(pennies, 1);
   makeChange(0, quarters, dimes, nickels, pennies);
   CHECK_EQ(quarters, 0);
   CHECK_EQ(dimes, 0);
   CHECK_EQ(nickels, 0);
   CHECK_EQ(pennies, 0);

   CHECK_EQ(celsiusToFahrenheit(0.0), doctest::Approx(32.0));
   CHECK_EQ(celsiusToFahrenheit(100.0), doctest::Approx(212.0));

   CHECK_EQ(fahrenheitToCelsius(32.0), doctest::Approx(0.0));
   CHECK_EQ(fahrenheitToCelsius(212.0), doctest::Approx(100.0));
 }

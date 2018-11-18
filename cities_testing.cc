//Citites Testing File
//Includes testing for most functions in cities
//Other functions are simply tested visually by
//their printout in the console (operator overloads,
//finer parts of the random_permutation function, etc.

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "cities.hh"

TEST_CASE("Random Permutations: random_permutation method should create a randomized vector of unsigned integers.")
{
    //Unfortunately we made the mistake of making 
    SECTION("Random permutation should contain all elements from zero to len - 1.")
    {
        

/*
TEST_CASE("Reordering: reorder method for Cities class. Given a permutation and returns a Cities object.")
{
    //First we create a city object, and fill it with 
    //First we establish a couple vectors to test for reordering.
    //These will be the following:
    //test_perm_0 : {5, 4, 3, 2, 1, 0} B
    //test_perm_1 :
    //test_perm_2 :
    permutation
    SECTION
    REQUIRE(1 == 1);
}
*/

//Outline:
//Random perm: Test it has all the elements, and test each rand perm is different. Repeat for two lengths.\
//Total Path distance: Test that it has the correct value, test for several city paths (but easy stuff, squares etc.)
// >> << are tested visually/in programs (explain that in comment)
//reorder: test that reordering works with one cities object and the outline above; use string stream (Sstream << cities, then Sstream >> string that's tested)
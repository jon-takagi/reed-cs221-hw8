//Citites Testing File
//Includes testing for most functions in cities
//Other functions are simply tested visually by
//their printout in the console (operator overloads,
//finer parts of the random_permutation function, etc.

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "cities.hh"
#include <algorithm> //Needed for some tests, such as checking if a vector contains an element.
#include <fstream>
#include <sstream>

TEST_CASE("Random Permutations: random_permutation method should create a randomized vector of unsigned integers.")
{
    //Unfortunately we made the mistake of making a method of cities instead of a free-standing function, so we first generate a city object to work with here.
    auto test_city (new Cities());
    //Then we test to make sure random permutation produces a permutation with the appropriate elements, and that it is different each time(which should usually be the case with enough elements).
    //We can't easily test other parts of the randomness here, and have to rely on looking at actual output to make sure that it is random.
    SECTION("Random permutation should contain all elements from zero to len - 1.")
    {
        Cities::permutation_t random_0 = test_city->random_permutation(10);
        //loop through and require the vector to contain each integer
        for (unsigned int i = 0; i < 10; i++)
        {
            REQUIRE(std::find(random_0.begin(), random_0.end(), i) != random_0.end());
        }
        //Then we do this a few mor times for other random permutations.
        Cities::permutation_t random_1 = test_city->random_permutation(10);
        //loop through and require the vector to contain each integer
        for (unsigned int i = 0; i <10; i++)
        {
            REQUIRE(std::find(random_1.begin(), random_1.end(), i) != random_1.end());
        }
        Cities::permutation_t random_2 = test_city->random_permutation(10);
        //loop through and require the vector to contain each integer
        for (unsigned int i = 0; i <10; i++)
        {
            REQUIRE(std::find(random_2.begin(), random_2.end(), i) != random_2.end());
        }
    }
    
    SECTION("Random permutations should probably be different each time. If this test fails, try running it again.")
    {
        Cities::permutation_t random_0 = test_city->random_permutation(50);
        Cities::permutation_t random_1 = test_city->random_permutation(50);
        Cities::permutation_t random_2 = test_city->random_permutation(50);
        Cities::permutation_t random_3 = test_city->random_permutation(50);
        REQUIRE (random_0 != random_1);
        REQUIRE (random_0 != random_2);
        REQUIRE (random_0 != random_3);
        REQUIRE (random_1 != random_2);
        REQUIRE (random_1 != random_3);
        REQUIRE (random_2 != random_3);
    }
    
}    

TEST_CASE("Reordering: reorder method for Cities class. Given a permutation and returns a Cities object.")
{
    //First we create a city object and fill it with the five.tsv file.
    std::ifstream fs("five.tsv");
    Cities test_city({});
    fs >> test_city;
    fs.close();
    //Then we establish a couple vectors to test for reordering.
    //These will be the following:
    //test_perm_0 : {4, 3, 2, 1, 0} Backwards reorder
    //test_perm_1 : {3, 4, 1, 0, 2} Arbitrary reorder
    //test_perm_2 : {1, 0} Swap first two elements only
    Cities::permutation_t test_perm_0 = {4, 3, 2, 1, 0};
    Cities::permutation_t test_perm_1 = {3, 4, 1, 0, 2};
    Cities::permutation_t test_perm_2 = {1, 0};
    SECTION("Reordered cities should have the expected order.")
    {
        auto test_city_2 = test_city.reorder(test_perm_0);
        std::vector<Cities::coord_t> expected_0 = { {7, 7}, {15, 7}, {15, 12}, {2, 20}, {10, 5} };
        for (int i = 0; i <=4; i++)
        {
            REQUIRE(test_city_2.get_elements().at(0).first == expected_0.at(0).first);
            REQUIRE(test_city_2.get_elements().at(0).second == expected_0.at(0).second);
        }
        auto test_city_3 = test_city.reorder(test_perm_1);
        std::vector<Cities::coord_t> expected_1 = { {15, 7}, {7, 7}, {2, 20}, {10, 5}, {15, 12} };
        for (int i = 0; i <=4; i++)
        {
            REQUIRE(test_city_3.get_elements().at(0).first == expected_1.at(0).first);
            REQUIRE(test_city_3.get_elements().at(0).second == expected_1.at(0).second);
        }
        auto test_city_4 = test_city.reorder(test_perm_2);
        std::vector<Cities::coord_t> expected_2 = { {2, 20}, {10, 5}, {15, 12}, {15, 7}, {7, 7} };
        for (int i = 0; i <=4; i++)
        {
            REQUIRE(test_city_4.get_elements().at(0).first == expected_2.at(0).first);
            REQUIRE(test_city_4.get_elements().at(0).second == expected_2.at(0).second);
        }
    }
}

TEST_CASE("Total Path Distance: total_path_distance method should accurately calculate expected distances using the hypotenuse.")
{
    //Again we will create a cities object based off five.tsv. We will then test the path distance
    //and compare it to expected values, calculated by hand with the help of other programs.
    //We also are testing for the value to fall within a certain range of accuracy, rather than have a precise number of digits.
    //We then will reorder the city and test the expected path distances.
    //First we create a city object and fill it with the five.tsv file.
    std::ifstream fs("five.tsv");
    Cities test_city({});
    fs >> test_city;
    fs.close();
    //Then we establish our reordering vectors
    //test_perm_0 : {0, 1, 2, 3, 4} Standard order
    //test_perm_1 : {3, 4, 1, 0, 2} Arbitrary reorder from last case
    Cities::permutation_t test_perm_0 = {0, 1, 2, 3, 4};
    Cities::permutation_t test_perm_1 = {3, 4, 1, 0, 2};
    SECTION ("Initial city should have the expected path distance.")
    {
        REQUIRE (48.869888 <= test_city.total_path_distance(test_perm_0));
        REQUIRE (test_city.total_path_distance(test_perm_0) <= 48.869889 );
    }
    SECTION ("Reordered city should have expected path distance. If reorder tests have fail, this one should as well.")
    {
        REQUIRE (52.53071354 <= test_city.total_path_distance(test_perm_1));
        REQUIRE (test_city.total_path_distance(test_perm_1) <= 52.53071355 );
    }
}


//Outline:
//Total Path distance: Test that it has the correct value, test for several city paths (but easy stuff, squares etc.)
//reorder: test that reordering works with one cities object and the outline above; use string stream (Sstream << cities, then Sstream >> string that's tested)
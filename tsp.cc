#include <iostream>
#include <fstream>
#include "cities.hh"
#include <cassert>

// Write a new file called tsp.cc with a main() function that will perform the actual search.
int main(int argc, char** argv) {

    // The main() function reads in a cities file (the filename should be given as the first argument of the program).
    if(argc != 2) {
        std::cerr << "Incorrect number of arguments" << "\n";
        exit(11);
    }
    std::ifstream fs(argv[1]);
    Cities city({});
    fs >> city;
    fs.close();

    // It then iterates over a fixed number of iterations (say, one million).
    int iterations = 1000000;

    const int number_of_cities = city.size();

    Cities best_city({});
    double best_distance = std::numeric_limits<double>::infinity();
    Cities::permutation_t order = city.random_permutation(number_of_cities);

    // In each iteration,
    for(int i = 0; i < iterations; i++) {
    //     it generates a new random permutation;
        order = city.random_permutation(number_of_cities);
        city = city.reorder(order);
        //     evaluates the distance to travel the cities along this ordering;
        double dist = city.total_path_distance(order);
        //     compares it to the best (shortest) distance found so far,
        //     and if it's shorter,
        if(dist < best_distance) {
        //         replaces the cities object with the newly-reordered cities and
        //         prints out to the screen the iteration number,
        //         followed by a space (or tab) and the total distance of the new path.
            best_distance = dist;
            best_city = city;
            std::cout << i << "\t" << best_distance << "\n";
        }
    }

    // At the end of the loop, save your city ordering to a file called "shortest.tsv".
    std::ofstream outstream("shortest.tsv");
    outstream << city;
    return 0;
}

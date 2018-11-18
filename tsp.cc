#include <iostream>
#include <fstream>
#include "cities.hh"
int main(int argc, char** argv) {
    int iterations = 1000000;

    if(argc != 2) {
        std::cerr << "Incorrect number of arguments" << "\n";
        exit(11);
    }
    std::ifstream fs(argv[1]);
    Cities city({});
    fs >> city;
    fs.close();

    std::cout << city;
    const int number_of_cities = city.size();

    Cities best_city({});
    double best_distance = std::numeric_limits<double>::infinity();
    Cities::permutation_t order = city.random_permutation(number_of_cities);

    for(int i = 0; i < iterations; i++) {
        order = city.random_permutation(number_of_cities);
        // city = city.reorder(order);
        // double dist = city.total_path_distance(order);
        // if(dist < best_distance) {
        //     best_distance = dist;
        //     best_city = city;
        //     std::cout << i << "\t" << best_distance;
        // }
        best_distance --    ;
    }

    std::ofstream outstream("shortest.tsv");
    outstream << best_city;


    return 0;
}

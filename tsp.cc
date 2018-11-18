#include <iostream>
#include <fstream>
#include "cities.cc"
int main(int argc, char** argv) {
    int iterations = 1000000;

    if(argc != 2) {
        std::cerr << "Incorrect number of arguments" << "\n";
        exit(11);
    }
    std::ifstream fs(argv[1]);
    // fs.open(argv[1]);
    Cities city({});
    fs >> city;
    fs.close();

    Cities best_city({});
    double best_distance = std::numeric_limits<double>::infinity();
    for(int i = 0; i < iterations; i++) {
        city.reorder();
        double dist = city.total_path_distance();
        if(dist < best_distance) {
            best_distance = dist;
            best_city = city;
            std::cout << i << "\t" << best_distance;
        }
    }

    std::ofstream outstream("shortest.tsv");
    outstream << best_city;
    return 0;
}

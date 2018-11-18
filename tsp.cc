#include <iostream>
#include <fstream>
#include "cities.cc"
int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "Incorrect number of arguments" << "\n";
        exit(11);
    }
    std::ifstream fs(argv[1]);
    // fs.open(argv[1]);
    Cities city({});
    fs >> city;
    fs.close();
    std::cout << city;
    return 0;
}

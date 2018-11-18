#include <iostream>
#include "cities.cc"
int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "Incorrect number of arguments" << "\n";
        exit(11);
    }
    char[] source_name = argv[1];
    ifstream fs;
    fs.open(source_name);
    Cities
}

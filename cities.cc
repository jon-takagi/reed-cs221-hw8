#include "cities.hh"
#include <cmath>
#include <vector>
#include <random>

//returns the distance between two city coord pairs
double Cities::dist_between(coord_t city_a, coord_t city_b) const
{
    return std::hypot(static_cast<double>(city_a.first-city_b.first), static_cast<double>(city_a.second-city_b.second));//Cast as doubles so hypot returns doubles
}


Cities Cities::reorder(const permutation_t& ordering) const
{
    auto permuted_cities = new Cities();
    std::vector<coord_t> permuted_elmts = {};//empty vector
    for (int i : ordering)
    {
        permuted_elmts.push_back(this->city_elements_.at(i));//Takes element i of original cities object and puts it in
    }
    permuted_cities->city_elements_ = permuted_elmts;
    return *permuted_cities;
}
//Returns a random permutation of ints 0 to len-1
//This is implemented by making an ordered vector of said ints
//Then picking one of those ints at random, removing it from the
//vector (by swapping it to the last place and then popping it),
//and then adding it to the back of a new permutation vector.
//This is repeated until it's done.
//The ordered vector does then become unordered but we're just
//pulling out elements at random so the order should be arbitrary anyways.
Cities::permutation_t Cities::random_permutation(unsigned len)
{
    //first create the ordered vector
    permutation_t permuted_nums;
    for(int i = 0; i < len; i++) {
        nums.push_back(i);
    }
    std::random_shuffle(nums.front, nums.back); 
    return permuted_nums;
}

//Returns the total path distance for a given ordering of cities.
double Cities::total_path_distance(const permutation_t& ordering) const
{
    auto city_path = reorder(ordering).city_elements_;
    double distance = dist_between(city_path.at(0), city_path.at(city_path.size()-1));//Initialize distance as dist between first and last
    for (unsigned int i = 1; i < city_path.size(); i++)//loop the distance between city i and the city before it, from the second to the last city.
    {
        distance += dist_between(city_path.at(i), city_path.at(i-1));
    }
    return distance;
}
int Cities::size() {
    return this -> city_elements_.size();
}


//reads from the input istream
//while the stream is not done, make pairs of values
//relies on in reading a whole number
//as explained to me by robert
std::istream& operator >> (std::istream& in, Cities& cities_ls){
    while(in) {
        Cities::coord_t pair;
        in >> pair.first;
        in >> pair.second;
        cities_ls.city_elements_.push_back(pair);
    }
    return in;
}

//writes tab separated list
//each pair in the elements is written on a newline as tab separated values
std::ostream& operator << (std::ostream& os, Cities& cities_ls){
    for(Cities::coord_t elm: cities_ls.city_elements_){
        os << elm.first << "\t" << elm.second << "\n";
    }
    return os;
}

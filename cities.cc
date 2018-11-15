#include "cities.hh"
#include <cmath>

//returns the distance between twot city coord pairs
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

int main()
{
    return 0;
}
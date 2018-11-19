Partners: Eli Poppele and Jon Takagi

# README
## Contents
1. Declarations
2. Implementations
3. Files
4. Results and other notes

## Declarations
### cities.hh
This file contains the declarations for the cites class and relevant functions.
We decided to make reorder, total_path_distance, and random_permutation into public methods as they are all const functions and are needed for the tsp program.
We also made the << and >> operator overloads public so they could be used, as well as size and get_elements helper methods which we needed to implement for tsp.
We made the elements_ data member private, as we don't need any non-member functions to interface with it directly, and we also made the dist_between helper method private since it is used only for the total_path_distance method.

## Implementations
### cities.cc
Most of the actual functions here should be well commented and explained in the file itself. We chose to implement the random_permutation method with a random shuffle function from the stl, and we also created the dist_between helper method to be used for the total_path_distance method.
### tsp.cc
This function works about as the assignment said it should (I hope). It is called with a .tsv file as a single argument, and the instreams that file and runs one million random iterations over that file, checking for the shortest city path. It prints each shortest path as it is found, and saves the final result in the file "shortest.tsv."

## Files
### README.md
This file, .md for the formatting (this file should look nice when read on github.com; if you're reading this just in a text editor, it won't be as nice.
### cities
There should be a cities.hh file for declarations, as described above, as well as a cities.cc for implementations. There may also be a .o object file which can be ignored.
### testing
In this repository, there should be a cities_testing.cc file (and maybe the .o) as well as the same file with no extension, which should be the testing program. These are kinda redundant given that our program more or less sees that they're all functional, but may be useful in coming weeks as we change our methods. The testing framework is implemented with Catch2, so there should also be a catch.hpp file in the repository to implement this.
### tsp
TSP is our main program that does the random searching for a shortest path. The .cc should have the implementations and declarations all in one file, and the file without extension should be the program itself.
### .tsv files
These include challenge.tsv, the fifty city list given by the assignment, as well as five.tsv and linear.tsv, also given by the assignment. Shortest.tsv is the output of our shortest path from the fifty city list, while speed.tsv is the output from the console after calling tsp on challenge.tsv (it shows the work done to find the shortest path).
### .gif files
Here we have challenge.gif, which shows the plot of five.tsv, and challenge-big.gif, which does the same for challenge.tsv, showing fifty cities. We also have shortest.gif, which shows the shortest path found among the fifty cities, and speed.gif, which is a plot showing the time taken and speed of said calculation.

## Results and other notes
We found that the output at fifty cities to be very unoptimal. A monkey with a marker could likely have done better, but on the other hand, a monkey with a computer could certainly not have done so well, so that's a small comfort.
To compile everything, just use the make file. There is currently one bug in our files, which is that the shortest.gif was based off an earlier, incorrect reordering which had the coordinate (0,0) accidentally included. The image has not been updated since, but otherwise reflects an accurate path.


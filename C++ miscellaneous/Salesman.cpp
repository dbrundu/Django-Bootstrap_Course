/********************************************
 * Travelling Salesman Problem
 *
 *  - naive implementation => O(n!)
 *  - use of std::next_permutation() to generate permutation of indices
 *  - print minimum distance and the corresponding permutation
 * 
 * author: D.Brundu
 * date:   23/01/2022
 * 
 * Compile and run with:
 * g++ -std=c++17 -Wall -pedantic Salesman.cpp && ./a.out
 * 
 ********************************************/



#include <iostream>
#include <string>
#include <vector>
#include <math.h> 
#include <algorithm>
#include <random>



struct City {

    double x;
    double y;
    
    City() = delete;
    City(double _x, double _y) : x(_x), y(_y) {}
    
    double DistanceTo(City* other){
        
        double xx = (x - other->x) * (x - other->x);
        double yy = (y - other->y) * (y - other->y);
        
        return std::sqrt ( xx + yy );    
    }
    
};




int main()
{
    // Setup random geneator
    std::random_device rd;  
    std::mt19937 gen( rd() ); 
    std::uniform_real_distribution<> rndm(0.0, 1.0);


    // Build all the N cities
    const int N = 10;
    
    std::vector<City*> cities;
    std::vector<int> idx;
    
    for(int i=0; i<N; ++i){
        double x = rndm(gen);
        double y = rndm(gen);
        cities.push_back( new City( x , y) );    
        idx.push_back(i);
    }
    
    
    // Choose the starting point (i.e. its index)
    // Remove the start index from the index list
    int start = 1;
    idx.erase (idx.begin() + start);
    
    
    // Calculate minimal distance
    // keep track of the good path 
    double min_distance = 1e20;
    std::vector<int> final_path;
    
    do {
        
        double distance = cities[start] -> DistanceTo( cities[idx[0]] );
        
        
        for(size_t i=1; i<idx.size()-1; ++i)
            distance += cities[idx[i]] -> DistanceTo( cities[idx[i+1]] );   
        
        
        if(distance < min_distance){
            min_distance = distance;
            final_path = idx;
        }
        
                     
    } while ( std::next_permutation(idx.begin(),idx.end()) );
    
    
    // Print results
    std::cout << "Min distance: " << min_distance << std::endl;
    
    std::cout << "Path: " << start << " ";
    for(auto i : final_path) std::cout << i << " ";
    
}


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

/********************************************
 * Given an array of integers nums find the first repeated element
 * 
 * author: D.Brundu
 * date:   23/01/2022
 * 
 * Compile and run with:
 * g++ -std=c++17 -Wall -pedantic RepeatedElement.cpp && ./a.out
 * 
 ********************************************/


bool FindFirstRepetition(const std::vector<int>& nums, int& element){

    std::unordered_set<int> already_seen;
    
    for(auto& n : nums){
    
        if( already_seen.find(n) != already_seen.end() ){
            element = n;
            return true;
        }
        
        already_seen.insert(n);
    }
    
    return false;  
    
}




int main()
{
    
    std::vector<int> nums = {2, 5, 5, 2, 3, 5, 2, 1, 2, 4};
    
    int repetition;
    
    if( FindFirstRepetition(nums, repetition) )
        std::cout << "Found! Element: " << repetition << std::endl;
    else
        std::cout << "Not Found any repeader element: "<< std::endl;
    
}


#include <iostream>
#include <vector>
#include <utility>

/********************************************
 * Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 * not use the same element twice.
 * 
 * author: D.Brundu
 * date:   23/01/2022
 * 
 * Compile and run with:
 * g++ -std=c++17 -Wall -pedantic TwoSum.cpp && ./a.out
 * 
 ********************************************/


std::pair<int,int> NaiveSolution(const std::vector<int>& nums, int target){
    
    for(size_t i=0; i<nums.size(); ++i){
        for(size_t j=0; j<nums.size(); ++j){
            
            if(i==j) continue;
            
            if(nums[i]+nums[j] == target) 
                return std::make_pair(i,j);
        }
    }  
    
    return std::make_pair(-1,-1);

}



std::pair<int,int> BetterSolution(const std::vector<int>& nums, int target){
    
    
    //using the fact that the vector is ordered
    size_t l = 0;
    size_t r = nums.size()-1;
    
    while( l <= r ){
        
        int sum = nums[l] + nums[r];
        
        if(sum == target) 
            return std::make_pair(l,r);
            
        else if(sum > target)
            r--;
            
        else 
            l++;
        
    }
    
    return std::make_pair(-1,-1);

}





int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    // Naive solution ==> O(n^2)
    std::pair<int,int> results_1 = NaiveSolution( nums, target);
    
    // Better solution ==> O(n) using the fact the array is ordered
    std::pair<int,int> results_2 = BetterSolution( nums, target);
    
    
    // Better solution ==> O(n) without using the fact the array is ordered
    // still to be implemented
    //std::pair<int,int> results_3 = MuchBetterSolution( nums, target);    
    
    
    std::cout << results_1.first << " " << results_1.second << std::endl;
    std::cout << results_2.first << " " << results_2.second << std::endl;
    
}


/********************************************
 * Three ways of factorial calculation
 *
 *  - iterative calculation with for loop
 *  - recursive calculation
 *  - compile time calculation using templates
 * 
 * author: D.Brundu
 * date:   01/02/2022
 * 
 * Compile and run with:
 * g++ -std=c++17 -O3 -Wall -pedantic Factorial.cpp && ./a.out
 * 
 ********************************************/
 
#include <iostream>


int FactorialIterative(int n){

    int result = 1;
    
    for(int i=1; i<=n; ++i) 
        result *= i;
    
    return result;
    
}




int FactorialRecursive(int n){

    // base case
    if(n<=1) return 1;
    
    // recursive case
    else return n * FactorialRecursive(n-1);
    
}




template<int N>
constexpr int FactorialCompileTime(){
    
    return N * FactorialCompileTime<N-1>();
    
}

template<>
constexpr int FactorialCompileTime<0>(){ return 1; }




int main()
{

    std::cout << FactorialIterative(5)     << std::endl;
    
    std::cout << FactorialRecursive(5)     << std::endl;
    
    constexpr int x = FactorialCompileTime<5>();
    std::cout << x << std::endl;
    
}


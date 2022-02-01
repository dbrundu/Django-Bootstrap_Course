/********************************************
 * Three ways of Fibonacci calculation
 *
 *  - iterative calculation with for loop
 *  - recursive calculation
 *  - compile time calculation using templates
 * 
 * author: D.Brundu
 * date:   01/02/2022
 * 
 * Compile and run with:
 * g++ -std=c++17 -O3 -Wall -pedantic Fibonacci.cpp && ./a.out
 * 
 ********************************************/
 
#include <iostream>
#include <vector>


int FibonacciIterative(int n){

    std::vector<int> sequence = {0, 1};
    
    for(int i=2; i<=n; ++i) 
        sequence.push_back( sequence[i-2] + sequence[i-1]);
    
    return sequence[n];
    
}




int FibonacciRecursive(int n){

    // base case
    if(n<=1) return n;
    
    // recursive case
    else return FibonacciRecursive(n-2) + FibonacciRecursive(n-1) ;
    
}




template<int N>
constexpr int FibonacciCompileTime(){
    
    return FibonacciCompileTime<N-2>() + FibonacciCompileTime<N-1>()  ;
    
}

template<>
constexpr int FibonacciCompileTime<0>(){ return 0; }

template<>
constexpr int FibonacciCompileTime<1>(){ return 1; }




int main()
{
    std::cout << FibonacciIterative(8) << std::endl;
    
    std::cout << FibonacciRecursive(8) << std::endl;
    
    constexpr int x = FibonacciCompileTime<8>();
    std::cout << x << std::endl;
    
}


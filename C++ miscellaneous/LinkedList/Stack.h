/****************************************
 * 
 * Simple stack based on 
 *  1) forward linked list implementation
 *     with templated values
 *  2) vectors
 *
 * author: D.Brundu
 * date:   25/01/2022
 * 
 * Compile and run with:
 * g++ -std=c++17 -Wall -pedantic main.cpp && ./a.out
 * 
 * 
 * *************************************/

#ifndef STACK_H_
#define STACK_H_


#include <iostream>
#include <./LinkedList.h>



template<typename T>
class Stack1 {
    
private:
    LinkedList<T>* list;
    
    
public:

    Stack1() = delete;

    Stack1(T val){
        list = new LinkedList<T>(val);    
    }
    
    
    T Peek(){
        return list->Get( list->GetSize()-1 );
    }
    
    inline void Push(T value){
        list->Append(value);
    }
    
    inline void Pop(){
        list->Remove( list->GetSize()-1 );
    }
    
    inline void Print(){
        list->PrintList();
    }
    
    
};




template<typename T>
class Stack2 {
    
private:
    LinkedList<T>* list;
    std::vector<T> vec;
    
    
public:

    Stack2() = delete;

    Stack2(T val){
        vec.push_back(val);
    }
    
    
    T Peek(){
        return vec[vec.size()-1];
    }
    
    inline void Push(T value){
        vec.push_back(value);
    }
    
    inline void Pop(){
        vec.pop_back();
    }
    
    inline void Print(){
        for(auto const& x : vec) std::cout << x << std::endl;
    }
    
    
};

#endif

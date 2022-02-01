/****************************************
 * 
 * Simple queue based on 
 *  forward linked list implementation
 *  with templated values
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
class Queue {
    
private:
    LinkedList<T>* list;
    
    
public:

    Queue() = delete;

    Queue(T val){
        list = new LinkedList<T>(val);    
    }
    
    
    T Peek(){
        return list->Get(0);
    }
    
    inline void Unqueue(T value){
        list->Append(value);
    }
    
    inline void Dequeue(){
        list->Remove(0);
    }
    
    inline void Print(){
        list->PrintList(  );
    }
    
    
};

#endif

/****************************************
 * 
 * Simple forward linked list implementation
 * with templated values
 * 
 * author: D.Brundu
 * date:   25/01/2022
 * 
 * Compile and run with:
 * g++ -std=c++17 -Wall -pedantic main.cpp && ./a.out
 * 
 * 
 * *************************************/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>


template<typename T>
struct Node {
    
    Node() = delete;
    
    Node(T val) : value(val), nextptr(nullptr) {}
    
    T value;
    Node<T>* nextptr;
};





template<typename T>
class LinkedList {
    
private:

    size_t size;
    Node<T>* Headptr;
    Node<T>* Tailptr;
    
    
public:

    LinkedList() = delete;
    
    LinkedList(T value)
    {
        Add_first(value);
    }
    
    
    template<typename ...Us>
    LinkedList(T value, Us... values)
    {
        Add_first(value);
        Add_helper(values...);
    }
    
    
    void Append(T value){
    
        Node<T>* p = new Node<T>(value);
        Tailptr->nextptr = p;
        Tailptr = p;
        size++;
        
    }
    
    void Prepend(T value){
    
        Node<T>* p = new Node<T>(value);
        p->nextptr = Headptr;
        Headptr = p;
        size++;
        
    }
    
    
    void Insert(T value, size_t pos){
    
        
        if(pos <= 0) {
            Prepend(value);
            return;
        }
        
        
        if(pos >= size){
            Append(value); 
            return;
        } 
        
        Node<T>* p = new Node<T>(value);
        
        Node<T>* currentptr = TraverseListToPos(pos-1);
        Node<T>* nextptr    = currentptr->nextptr;
        
        currentptr->nextptr = p;
        p->nextptr = nextptr;
            
        size++;
        
    }
    
    
    void Remove(size_t pos){
    
        if(pos<0 || pos>=size){
            std::cout << "Error: wrong index when removing item" << std::endl;
            return;   
        }

        if(pos==0){
            Node<T>* p = Headptr;
            Headptr = p->nextptr;
            delete p;
        } else {    
            Node<T>* toremoved     = TraverseListToPos(pos);
            Node<T>* prevtoremoved = TraverseListToPos(pos-1);
            prevtoremoved->nextptr = toremoved->nextptr;
            delete toremoved;
        }

        size-- ;
        
    }
    
    
    
    
    Node<T>* TraverseListToPos(size_t pos){
        
        Node<T>* currentptr = Headptr;  
        
        for(size_t i=0; i<pos; ++i)
            currentptr = currentptr->nextptr;
            
        return currentptr;
    }
    
    
    
    void PrintList(){
    
        Node<T>* currentptr = Headptr;
        
        for(size_t i=0; i<size; ++i){
            std::cout << i << ") " << currentptr->value << std::endl;
            currentptr = currentptr->nextptr;
        }    
        
    }
    
    
    
    
    inline size_t GetSize(){ return size; }
    
    
    
    
    inline T Get(size_t index){ 
        
        if(index<0 || index>=size){
            std::cout << "Error: wrong index when getting item" << std::endl;
            return T();
        }
        
        Node<T>* currentptr = TraverseListToPos(index);
        
        return currentptr->value;
        
    }
    

private:

    inline void Add_first(T val){
        Headptr = new Node<T>(val);
        Tailptr = Headptr;
        size = 1;    
    }

    inline void Add_helper() {}

    template<typename ...Us>
    inline void Add_helper(T val, Us... values)
    {
        Append(val);
        Add_helper(values...);
    }

};

#endif

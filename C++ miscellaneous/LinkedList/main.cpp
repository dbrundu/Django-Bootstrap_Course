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


#include <iostream>
#include <./LinkedList.h>





int main()
{
    
    LinkedList<double> a = LinkedList<double>(1.0, 2.0, 3.0);
    
    
    a.Append(5.0);
    a.Append(5.0);
    a.Append(6.0);
    
    a.Prepend(0.0);
    
    a.Insert(4.0, 4);
    
    a.Remove(6);
    
    a.PrintList();
    
    
}


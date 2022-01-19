/*
 * Modular design using Factory Method for creation
 * Author: D. Brundu
 * 2022
 *
 * Simply run with: 
 * g++ -std=c++17 -Wall -pedantic modular_design.cpp && ./a.out
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib>



/*
 * Module
 * Module implement the same interface so that the module manager can refer
 * to the interface and not the concrete module
 */
class Module
{
    
public:
  
  virtual ~Module() {}
  
  virtual void init() = 0;
  virtual void run() = 0;
  virtual void finalize() = 0;

};


/*
 * One Concrete Module
 */
class ConcreteModuleA : public Module
{
public:
  ~ConcreteModuleA() {}
  
    virtual void init(){
        std::cout << "Init A" << std::endl;    
    }
    
    virtual void run(){
        std::cout << "Run A" << std::endl;    
    }
    
    virtual void finalize(){
        std::cout << "Finalize A" << std::endl;    
    }

};



/*
 * One Concrete Module
 */
class ConcreteModuleB : public Module
{
public:
  ~ConcreteModuleB() {}
  
    virtual void init(){
        std::cout << "Init B" << std::endl;    
    }
    
    virtual void run(){
        std::cout << "Run B" << std::endl;    
    }
    
    virtual void finalize(){
        std::cout << "Finalize B" << std::endl;    
    }

};



/*
 * One Concrete Module
 */
class ConcreteModuleC : public Module
{
public:
  ~ConcreteModuleC() {}
  
    virtual void init(){
        std::cout << "Init C" << std::endl;    
    }
    
    virtual void run(){
        std::cout << "Run C" << std::endl;    
    }
    
    virtual void finalize(){
        std::cout << "Finalize C" << std::endl;    
    }

};





/*
 * Module Manager
 * implements factory method that is responsible for creating
 * one or more concrete modules 
 */
class ModuleManager
{
private:
  std::vector<Module*> modules;

  
 Module* createmodule(int selector) 
  {
    
    if(selector<0 || selector >2) {
        std::cout << "Error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    
    switch ( selector )
    {
        case 0:
            return new ConcreteModuleA() ;
            break;
        case 1:
             return new ConcreteModuleB() ;
            break;
        case 2:
             return new ConcreteModuleC() ;
            break;
        default:
            return new ConcreteModuleA() ;;
    }
  }
  
  
  
public:

 template<size_t N>
 void CreateModules(std::array<bool, N> some_config){
     
     for(size_t i=0; i<N; ++i){
        if(some_config[i]) 
            modules.push_back( createmodule(i) );    
     } 
     
 }
  
  
 void Run(double some_input) 
  {
    for(auto m : modules)
        m->run();
  }

};




int main()
{
    
  // Configuration ==> runtime variables
  // Instantiate A and C modules only
  std::array<bool, 3> some_config = {true, false, true}; 
  
  // An input or anything changing event by event
  double some_input = 0.0; 

    
  // Manager will create the modules based
  // on the configuration and run them
  ModuleManager *manager = new ModuleManager();
  
  manager->CreateModules(some_config);
  
  manager->Run( some_input );


  // Cleaning  
  delete manager;
  return 0;
}

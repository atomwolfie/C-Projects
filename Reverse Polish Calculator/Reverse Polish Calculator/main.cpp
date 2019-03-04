//
//  main.cpp
//  Reverse Polish Calculator
//
//  Created by Aaron Adams on 11/4/15.
//  Copyright (c) 2015 Aaron Adams. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <exception>
#include <sstream>
#include "Rational.h"



template<typename C, typename F>
void apply(C & container, F f){
    
    if(container.size() < 2) throw std:: runtime_error ("Not enough operands");
    
    auto second = container.back();
    container.pop_back();
    
    auto first = container.back();
    container.pop_back();
    
    
    auto result = f(first, second);
    std:: cout << first << " op " << second << " = " << result << std::endl;
    
    container.push_back(result);
    
    
}







int main(int argc, const char * argv[]) {
    
    
    
    
    std :: vector<Rational> stack;
    
    
    
    try{
    
    while(true){
        std:: cout << "Enter equation: ";
        std :: string input;
        std:: getline(std::cin, input);
        std:: stringstream ss(input);
        std:: string value;
        
        while(ss >> value){
            
            
            
            
            if(value[0] == 'e') return EXIT_SUCCESS;
            if(value[0] =='c'){
                stack.clear();
            }
            if(value[0] == '+'){
                
                apply(stack, [](Rational a, Rational b){return a + b;});
                
            }
            else if(value[0] == '-'){
                
                apply(stack,[](Rational a, Rational b){return a - b;});
                
            }
            else if(value[0] == '*'){
                
                apply(stack,[](Rational a, Rational b){return a * b;});
                
            }
            else if(value[0] == '/'){
                
                apply(stack,[](Rational a, Rational b){return a / b;});
                
            }
            else{
                
                std:: stringstream temp(value);
                
                Rational a;
                
                temp >> a;
                
                
                stack.push_back(a);
            }

            
        }
        
        
        
    }
        
    }
    
    catch(std:: exception& e){
        std::cout << e.what();
        stack.clear();
    }
    catch(...){
        
        std::cout << "Unexpected exception"<<std::endl;
        std::cout<<"Clearing Stack..."<<std::endl;
        stack.clear();
    }
    
    
    
    
    
    
    
    
    
    return 0;
}

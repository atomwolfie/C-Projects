//
//  main.cpp
//  Rational Numbers
//
//  Created by Aaron Adams on 10/9/15.
//  Copyright (c) 2015 Aaron Adams. All rights reserved.
//

#include <iostream>
#include "Rational.h"
#include <vector>





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









using namespace std;

int main() {
    
    
    std :: vector<int> stack;

    
    
    Rational a, b;
    
    cout << "Enter first Rational number: ";
    cin >> a;
    
    cout << "\nEnter second Rational number: ";
    cin >>b;
    
    
    
    
    try{
        
        while(true){
            std:: cout << "Enter equation: ";
            std :: string input;
            std:: getline(std::cin, input);
            
            
            
                
                
                
                if(input[0] == 'e') return EXIT_SUCCESS;
                if(input[0] =='c'){
                    stack.clear();
                }
                if(input[0] == '+'){
                    
                    apply(stack, [](int a, int b){return a + b;});
                    
                }
                else if(input[0] == '-'){
                    
                    apply(stack,[](int a, int b){return a - b;});
                    
                }
                else if(input[0] == '*'){
                    
                    apply(stack,[](int a, int b){return a * b;});
                    
                }
                else if(input[0] == '/'){
                    
                    apply(stack,[](int a, int b){return a / b;});
                    
                }
                else{
                    
                    auto number = atoi(input.c_str());
                    stack.push_back(number);
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
    
    
    
    

    
    
    if(a < b) cout << a << ' ' << '<' << ' ' << b << endl;
    
    if(a > b) cout << a << ' ' << '>' << ' ' << b << endl;
    
    if(a <= b) cout << a << " <= " << b << endl;
    
    if(a >= b) cout << a << " >= " << b << endl;
    
    if (a!= b) cout << a << " != " << b << endl;
    
    if (a == b) cout << a << " == " << b << endl;
    
    if (a != b) cout << a << " != " << b << endl;
    
    cout << a << " + " << b << " = " << a + b << endl;
    
    cout << a << " - " << b << " = " << a - b << endl;
    
    cout << a << " * " << b << " = " << a * b << endl;
    
    cout << a << " / " << b << " = " << a / b << endl;
    
    
    
    cout << a << " +=  " <<  b << " = " << (a+=b) << endl;
    
    cout << a << " -=  " <<  b << " = " << (a-=b) << endl;
    
    cout << a << " *=  " <<  b << " = " << (a*=b) << endl;
    
    cout << a << " /= " << b << " = " << (a/=b) << endl;


    
    
    
   
    
    return 0;
}

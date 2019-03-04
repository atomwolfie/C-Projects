//
//  main.cpp
//  Rational Numbers
//
//  Created by Aaron Adams on 10/9/15.
//  Copyright (c) 2015 Aaron Adams. All rights reserved.
//

#include <iostream>
#include "Rational.h"


using namespace std;

int main() {
    
    Rational a, b;
    
    cout << "Enter first Rational number: ";
    cin >> a;
    
    cout << "\nEnter second Rational number: ";
    cin >>b;
    
    
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

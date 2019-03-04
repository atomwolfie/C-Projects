//
//  main.cpp
//  Prime Equation Disproof
//
//  Created by Aaron Adams on 9/8/16.
//  Copyright (c) 2016 Aaron Adams. All rights reserved.
//

#include <iostream>


using namespace std;



void doit(int);

int main(int argc, const char * argv[]) {
    
    
//    int i = 0;
//    
//    for(int i = 0; i < 100; ++ i){
//        
//        double y = i;
//        
//        y = (y * y) + y + 41;
//        
//        cout<<"input " << i << " output: " << y ;
//        
//        cout << endl << "divided by 3: " << y/ 3.0 << " divided by 7: " << y/7.0 << endl << endl;
//        
//        
//    }
    
    int x = 16;
    
    
    
    doit(x);
    
    
    
    
    
    
    return 0;
}


void doit(int n){
    int x = 0;
    
    if (n <1) return;
    
    for (int i=0; i < n ; i++){
        
        x++;
    
    }
    
    cout << x << endl << endl;
    
    doit(n-1);
    
    doit(n-1);
    
}



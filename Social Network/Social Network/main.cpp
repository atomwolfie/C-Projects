//
//  main.cpp
//  Social Network
//
//  Created by Aaron Adams on 11/15/16.
//  Copyright © 2016 Aaron Adams. All rights reserved.
//
#include "UnionFind.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;
int main() {
    
    
    //ENTER AMMOUNT OF MEMBERS YOU WOULD LIKE TO TEST, RAND() just runs the same vaule everytime
    
    int numMembers = rand();

    
    cout << "There are " << numMembers << " members" <<endl;
    int numDays = 0;
    UnionFind netWork(numMembers);
    
    
    bool allConnected = false;
    
    
    while(allConnected == false){
        
        int friend1 = rand()%numMembers;
        int friend2 = rand()%numMembers;
        
        //only merging if they aren't the same value and aren't already part of the same set
        if(friend1 != friend2 && netWork.connected(friend1, friend2) == 0){
        netWork.merge(friend1, friend2);
        }
        //When there's only one set left I know everything is done and connected
        if(netWork.cnt() == 1){
            allConnected = true;
        }
        
        numDays++;
    }
    
    
    cout << "It took " << numDays << " days for everyone to become friends" << endl;
    
    cout << "Number of finds: " << netWork.numFinds << endl;
    cout << "Number of unions: " << netWork.numUnions << endl;

    
    
    return 0;
}

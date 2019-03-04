//
//  main.cpp
//  Word Ladder
//
//  Created by Aaron Adams on 9/6/16.
//  Copyright (c) 2016 Aaron Adams. All rights reserved.
//

//#include <iostream>
//#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "wordLadder.h"

using namespace std;

int inDictionary (vector<string>, string);

int main(int argc, const char * argv[]) {
    
    vector<string> dictionary;
    string word;
    
    
    
    ifstream myfile("dictionary.txt");
    
    
    copy(istream_iterator<string>(myfile),
         
         istream_iterator<string>(),
         
         back_inserter(dictionary));
    
    try {
        
        cout << "Dictionary created " << endl << endl;
        
        cout << "The size of your dictionary is: " << dictionary.size() << endl << endl;
        
    } catch(...) {
       
        cout << "Data Unavailable\n Cannot find dictionary.txt";
    }
    
    
    
    string startingWord;
    string endingWord;
 

    
    cout << "dictionary test" << endl;
    for(int i = 0; i < 10; ++i){
        cout << dictionary[i] << endl;
        
    }
    cout << endl;
    
    
    LinkedList queue;
    startingWord = "slow";
    endingWord = "fast";
    cout << "slow --> fast" << endl;
    vector<string> startingVector = {startingWord};
    queue.append(startingVector);
    queue.nextTier(dictionary, queue, endingWord);
    
    
//    LinkedList queue1;
//    string startingWord1 = "oops";
//    string endingWord1 = "pops";
//    cout << endl <<  "oops --> pops" << endl;
//    vector<string> startingVector1 = {startingWord1};
//    queue1.append(startingVector1);
//    queue1.nextTier(dictionary, queue1, endingWord1);
    
    
    
    
    
//    LinkedList queue2;
//    string startingWord2 = "vicki";
//    string endingWord2 = "allen";
//    cout << endl <<  "vicki --> allen" << endl;
//    vector<string> startingVector2 = {startingWord2};
//    queue2.append(startingVector2);
//    queue2.nextTier(dictionary, queue2, endingWord2);

    
    
//    LinkedList queue3;
//    string startingWord3 = "happily";
//    string endingWord3 = "angrily";
//    cout << endl <<  "happily --> angrily" << endl;
//    vector<string> startingVector3 = {startingWord3};
//    queue3.append(startingVector3);
//    queue3.nextTier(dictionary, queue3, endingWord3);
//    

    
    //LinkedList queue4;
//    string startingWord4 = "stone";
//    string endingWord4 = "money";
//    
//    cout << endl <<  "stone --> money" << endl;
//    
//    vector<string> startingVector4 = {startingWord4};
//    
//    
//    queue4.append(startingVector4);
//    
//    queue4.nextTier(dictionary, queue4, endingWord4);
//    
    
    
    
    
    return 0;
}




